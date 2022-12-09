#ifndef __GRAPHICSOBS_H__
#define __GRAPHICSOBS_H__

#include <memory>
#include "window.h"
#include "observer.h"
#include "videostudio.h"

class GraphicsObs: public Observer {
    VideoStudio *v;
    std::unique_ptr<Xwindow> graphicWindow;

    const int frameWidth;
    const int frameHeight;

    public:
        GraphicsObs(VideoStudio *v, int width, int height);
        ~GraphicsObs();

        void notify() override;
};

#endif
