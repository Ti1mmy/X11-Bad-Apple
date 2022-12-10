#include "video.h"
using namespace std;

Video::Video(const vector<const vector<string>*> &frames, int numFrames, int height, int width):
            frameList{&frames}, frameWidth{width}, frameHeight{height}, currentFrame{0} {}

Video::~Video() {
    for (auto frame: (*frameList)) delete frame;
}

int Video::getFrameWidth() const { return frameWidth; }

int Video::getFrameHeight() const { return frameHeight; }

int Video::frameNum() const { return currentFrame; }

const vector<string>& Video::getCurrentFrame() const { return *((*frameList)[currentFrame]); }

Video& Video::operator++() {
    ++currentFrame;
    return *this;
}
