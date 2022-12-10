#ifndef __FRAME_H__
#define __FRAME_H__

#include <vector>
#include <string>
#include <memory>
class Video {
    const std::vector<const std::vector<std::string>*>* frameList;
    const int frameWidth;
    const int frameHeight;
    int currentFrame;
    public:
        Video(const std::vector<const std::vector<std::string>*> &frames, int numFrames, int height, int width);
        ~Video();
        
        // getters
        int getFrameWidth() const;
        int getFrameHeight() const;
        int frameNum() const;
        const std::vector<std::string>& getCurrentFrame() const;

        // operator overload
        Video& operator++();
};

#endif
