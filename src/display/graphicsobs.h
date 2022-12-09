#ifndef __GRAPHICSOBS_H__
#define __GRAPHICSOBS_H__

#include <memory>
#include "window.h"

class GraphicsObs: public Observer {
    VideoStudio *v;
    std::unique_ptr<XWindow> graphicWindow;

    const int frameWidth;
    const int frameHeight;

    public:
        TextObserver(VideoStudio *v, int width, int height);
        ~Textobserver();

        void notify() override;
}

#endif
