#include "graphicsobs.h"

using namespace std;

GraphicsObs::GraphicsObs(VideoStudio *v, int width, int height): v{v}, frameWidth{width}, frameHeight{height} {
    v->attach(this);
}

GraphicsObs::~GraphicsObs() { v->detach(this); }

void GraphicsObs::notify() { graphicWindow->drawFrame(v->getState()); }
