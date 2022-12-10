#ifndef __WINDOW_H__
#define __WINDOW_H__
#include <X11/Xlib.h>
#include <iostream>
#include <string>
#include <vector>

class Xwindow {
  Display *d;
  Window w;
  int s;
  GC gc;
  std::vector<unsigned long> colours;
  const int width;
  const int height;
  std::vector<std::string> lastFrame;
  
 public:
  Xwindow(int width=500, int height=500);  // Constructor; displays the window.
  ~Xwindow();                              // Destructor; destroys the window.
  Xwindow(const Xwindow&) = delete;
  Xwindow &operator=(const Xwindow&) = delete;

  // Draws a bitmap
  // [This thing is fast] - Whenever draw calls need to be done, they should ideally be using this
  void drawFrame(std::vector<std::string>& frame);

};

#endif
