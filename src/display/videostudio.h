#ifndef __VIDEOSTUDIO_H__
#define __VIDEOSTUDIO_H__

#include <memory>
#include "video.h"

class Video;

class VideoStudio: public Subject {
    std::shared_ptr<Video> video;
    public:
        explicit VideoStudio(std::shared_ptr<Video> v);

        int getFrameNum() const;
        const std::vector<std::string>> &getCurrentFrame() const;
};

#endif
