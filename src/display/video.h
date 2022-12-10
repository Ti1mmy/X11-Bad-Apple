#ifndef __FRAME_H__
#define __FRAME_H__

#include <vector>
#include <string>
#include "colours.h"
#include "../bad_apple_pixmap_frames-min.h"

class Video {
    std::vector<std::vector<std::vector<colour>>> frameList;
    const int frameWidth;
    const int frameHeight;
    int currentFrame;
    public:
        Video(const colour* frames[NUM_FRAMES_H][FRAME_HEIGHT_H], int numFrames, int height, int width);

        // getters
        int getFrameWidth() const;
        int getFrameHeight() const;
        int frameNum() const;
        const std::vector<std::vector<colour>>& getCurrentFrame() const;

        // operator overload
        Video& operator++();
};

#endif
