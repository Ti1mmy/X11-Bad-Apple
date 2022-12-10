#include "graphicsobs.h"
#include "../bad_apple_pixmap_frames-min.h"

using namespace std;

GraphicsObs::GraphicsObs(VideoStudio *v, int width, int height): v{v}, frameWidth{width}, frameHeight{height} {
    graphicWindow = make_Unique<Xwindow>(FRAME_WIDTH, FRAME_HEIGHT);
    v->attach(this);
}

GraphicsObs::~GraphicsObs() { v->detach(this); }

void GraphicsObs::notify() { graphicWindow->drawFrame(v->getState()); }
