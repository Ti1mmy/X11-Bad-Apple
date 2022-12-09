#ifndef __VIDEOSTUDIO_H__
#define __VIDEOSTUDIO_H__

#include <memory>
#include "subject.h"
#include "video.h"

class Video;

class VideoStudio: public Subject {
    Video* video;
    public:
        explicit VideoStudio(Video *v);

        int getFrameNum() const;
        virtual const std::vector<std::string> &getState() const override;
};

#endif
