#include "graphicsobs.h"

using namespace std;

GraphicsObs::GraphicsObs(VideoStudio *v, int width, int height): v{v}, width{width}, height{height} {
    v->attach(this);
}

GraphicsObs::~GraphicsObs() { v->detach(this); }

GraphicsObs::notify() { graphicWindow->drawFrame(v->getCurrentFrame()); }
