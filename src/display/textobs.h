#ifndef __TEXTOBS_H__
#define __TEXTOBS_H__

#include <iostream>
#include "videostudio.h"

class TextObserver: public Observer {
    VideoStudio *v;
    std::ostream &out = std::cout;
    void notify() override;
    
    public:
        explicit TextObserver(VideoStudio *v);
        ~TextObserver();
};

#endif
