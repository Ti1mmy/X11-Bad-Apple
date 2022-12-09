#ifndef __FRAME_H__
#define __FRAME_H__

#include <vector>
#include <string>

class Video {
    std::vector<std::vector<const std::string>> frameList;
    const int frameWidth;
    const int frameHeight;
    const int currentFrame;
    public:
        Video(const &std::vector<std::vector<const std::string>> frames);

        // getters
        int getFrameWidth() const;
        int getFrameHeight() const;
        int frameNum() const;
        const std::vector<const std::string>& getCurrentFrame() const;

        // operator overload
        Video& operator++();
};

#endif
