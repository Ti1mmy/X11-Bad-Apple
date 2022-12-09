//////////////////////////////////////////////////////////////////////////////
// Code originated from Assignment 4 Q4
// Provided by the CS246 Instructors

// Code has been modified by our team, and modifications have been documented.
//////////////////////////////////////////////////////////////////////////////

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

  d = make_unique<Display>(XOpenDisplay(NULL));
  if (d == NULL) {
    cerr << "Cannot open display" << endl;
    exit(1);
  }
  s = DefaultScreen(d.get());
  w = XCreateSimpleWindow(d.get(), RootWindow(d.get(), s), 10, 10, width, height, 1,
                          BlackPixel(d.get(), s), WhitePixel(d.get(), s));
  XSelectInput(d.get(), w, ExposureMask | KeyPressMask);
  XMapRaised(d.get(), w);

  Pixmap pix = XCreatePixmap(d.get(), w, width,
        height, DefaultDepth(d.get(), DefaultScreen(d.get())));
  gc = XCreateGC(d.get(), pix, 0, (XGCValues *)0);

  XFlush(d.get());
  XFlush(d.get());

  // Set up colours.
  XColor xcolour;
  Colormap cmap;
  // https://en.wikipedia.org/wiki/X11_color_names#Color_name_chart
  // https://www.w3schools.com/colors/colors_x11.asp

  vector<string> color_vals {
    "white",
    "black",
  };

  cmap=DefaultColormap(d.get(), DefaultScreen(d.get()));

  colours.resize(color_vals.size());
  // Add colour vals to colours
  for(int i=0; i < (int)color_vals.size(); ++i) {
      XParseColor(d.get(), cmap,color_vals[i].c_str(), &xcolour);
      XAllocColor(d.get(), cmap, &xcolour);
      colours[i] = xcolour.pixel;
  }

  XSetForeground(d.get(), gc, colours[0]);

  // Make window non-resizeable.
  XSizeHints hints;
  hints.flags = (USPosition | PSize | PMinSize | PMaxSize );
  hints.height = hints.base_height = hints.min_height = hints.max_height = height;
  hints.width = hints.base_width = hints.min_width = hints.max_width = width;
  XSetNormalHints(d.get(), w, &hints);

  XSynchronize(d.get(), True);
  XStoreName(d.get(), w, "X11 Bad Apple!!");
  usleep(1000);

  // Make sure we don't race against the Window being shown
  XEvent ev;
  while(1) {
    XNextEvent(d.get(), &ev);
    if(ev.type == Expose) break;
  }
}

Xwindow::~Xwindow() {
  XFreeGC(d.get(), gc);
  XCloseDisplay(d.get());
}

void Xwindow:: drawFrame(std::vector<const std::string> frame); {
  // Extensively used documentation from this website:
  // https://tronche.com/gui/x/xlib/graphics/XGetImage.html

  // Performance: drawBitMap is highly optimized since it minimizes the amount of
  // draw-call requests from the server to the client.

  // Sprites are buffered in an XImage class and only displayed once
  // all pixels have been placed onto the XImage.
  unique_ptr<XImage> image = make_unique<XImage>(XGetImage(d, w, 0, 0, width, height, AllPlanes, 1));
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      char pixel = frame[y][x];
      
      // Optimization
      if (lastFrame[y][x] == pixel) continue;
      lastFrame[y][x] = pixel;

      if (pixel == '#') {
        XPutPixel(image.get(), x, y, colours[0]);
      } else if (pixel == ' ') {
        XPutPixel(image.get(), x, y, colours[1]);
      }
    }
  }
  XPutImage(d, w, gc, image.get(), 0, 0, 0, 0, numCols, numRows);
}
