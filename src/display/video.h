#ifndef __FRAME_H__
#define __FRAME_H__

#include <vector>
#include <string>

class Video {
    std::vector<std::vector<std::string>> frameList;
    const int frameWidth;
    const int frameHeight;
    int currentFrame;
    public:
        Video(const std::string **frames, int numFrames, int height, int width);

        // getters
        int getFrameWidth() const;
        int getFrameHeight() const;
        int frameNum() const;
        const std::vector<std::string>& getCurrentFrame() const;

        // operator overload
        Video& operator++();
};

#endif
