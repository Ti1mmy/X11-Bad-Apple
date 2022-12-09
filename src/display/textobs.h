#ifndef __TEXTOBS_H__
#define __TEXTOBS_H__

#include <iostream>
#include "observer.h"

class TextObserver: public Observer {
    VideoStudio *v;
    ostream &out = std::cout;
    void notify() override;
    
    public:
        explicit TextObserver(VideoStudio *v);
        ~Textobserver();
};

#endif
