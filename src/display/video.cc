#include "video.h"
using namespace std;

Video::Video(const vector<vector<string>>& frames):
            frameWidth{frames[0][0].length()}, frameHeight{frames[0].size()}, currentFrame{0} {
                const int numFrames = frames.size();
                for (const vector<string> &frame: frames) {
                    frameList.emplace_back(frame);
                }
            }

int Video::getFrameWidth() const { return frameWidth; }

int Video::getFrameHeight() const { return frameHeight; }

int Video::frameNum() const { return currentFrame; }

const vector<string>& Video::getCurrentFrame() const { return frameList[currentFrame]; }

Video& Video::operator++() {
    ++currentFrame;
    return *this;
}
