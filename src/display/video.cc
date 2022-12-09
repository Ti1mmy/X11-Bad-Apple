#include "video.h"
using namespace std;

Video::Video(const vector<vector<const string>>& frames):
            frameWidth{frames[0][0].length()}, frameHeight{frames[0].size()}, currentFrame{0} {
                const int numFrames = frames.size();
                frames.resize(numFrames);
                for (const vector<string> &frame: frames) {
                    frameList.emplace_back(frame);
                }
            }

Video::getFrameWidth() const { return frameWidth; }

Video::getFrameHeight() const { return frameHeight; }

Video::frameNum() const { return currentFrame; }

const vector<const string>& Video::getCurrentFrame() const { return frameList[currentFrame]; }

Video::Video& Video::operator++() {
    ++currentFrame;
    return *this;
}
