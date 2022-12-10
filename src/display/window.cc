#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <vector>
#include "window.h"

using namespace std;

Xwindow::Xwindow(int width, int height): width{width}, height{height} {
  string black = "";
  for (int i = 0; i < width; ++i) {
    black += '#';
  };
  lastFrame.resize(height, black);

  d = XOpenDisplay(NULL);
  if (d == NULL) {
    cerr << "Cannot open display" << endl;
    exit(1);
  }
  s = DefaultScreen(d);
  w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, width, height, 1,
                          BlackPixel(d, s), WhitePixel(d, s));
  XSelectInput(d, w, ExposureMask | KeyPressMask);
  XMapRaised(d, w);

  Pixmap pix = XCreatePixmap(d, w, width,
        height, DefaultDepth(d, DefaultScreen(d)));
  gc = XCreateGC(d, pix, 0, (XGCValues *)0);

  XFlush(d);
  XFlush(d);

  // Set up colours.
  XColor xcolour;
  Colormap cmap;
  // https://en.wikipedia.org/wiki/X11_color_names#Color_name_chart
  // https://www.w3schools.com/colors/colors_x11.asp

  vector<string> color_vals {
    "white",
    "black",
  };

  cmap=DefaultColormap(d, DefaultScreen(d));

  colours.resize(color_vals.size());
  // Add colour vals to colours
  for(int i=0; i < (int)color_vals.size(); ++i) {
      XParseColor(d, cmap,color_vals[i].c_str(), &xcolour);
      XAllocColor(d, cmap, &xcolour);
      colours[i] = xcolour.pixel;
  }

  XSetForeground(d, gc, colours[0]);

  // Make window non-resizeable.
  XSizeHints hints;
  hints.flags = (USPosition | PSize | PMinSize | PMaxSize );
  hints.height = hints.base_height = hints.min_height = hints.max_height = height;
  hints.width = hints.base_width = hints.min_width = hints.max_width = width;
  XSetNormalHints(d, w, &hints);

  XSynchronize(d, True);
  XStoreName(d, w, "X11 Bad Apple!!");
  usleep(1000);

  // Make sure we don't race against the Window being shown
  XEvent ev;
  while(1) {
    XNextEvent(d, &ev);
    if(ev.type == Expose) break;
  }
}

Xwindow::~Xwindow() {
  XFreeGC(d, gc);
  XCloseDisplay(d);
}

void Xwindow::drawFrame(const vector<string>& frame) {
  // Extensively used documentation from this website:
  // https://tronche.com/gui/x/xlib/graphics/XGetImage.html

  // Performance: drawBitMap is highly optimized since it minimizes the amount of
  // draw-call requests from the server to the client.

  // Sprites are buffered in an XImage class and only displayed once
  // all pixels have been placed onto the XImage.
  XImage* image = XGetImage(d, w, 0, 0, width, height, AllPlanes, 1);
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      char pixel = frame[y][x];
      
      // Optimization
      if (lastFrame[y][x] == pixel) continue;
      lastFrame[y][x] = pixel;

      if (pixel == '#') {
        XPutPixel(image, x, y, colours[0]);
      } else if (pixel == ' ') {
        XPutPixel(image, x, y, colours[1]);
      }
    }
  }
  XPutImage(d, w, gc, image, 0, 0, 0, 0, width, height);
  XDestroyImage(image);
  XSync(d, 1)
}
