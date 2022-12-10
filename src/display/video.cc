#include "video.h"
using namespace std;

Video::Video(char frames[500][720][961], int numFrames, int height, int width):
            frameHeight{height}, frameWidth{width}, currentFrame{0} {
                for (int i = 0; i < numFrames; ++i) {
                    vector<string> temp;
                    for (int j = 0; j < height; ++j) {
                        temp.emplace_back(frames[i][j]);
                    }
                    frameList.emplace_back(move(temp));
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
