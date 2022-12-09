#include "video.h"
using namespace std;

Video::Video(const string frames[][], int numFrames, int height):
            frameWidth{width}, frameHeight{height}, currentFrame{0} {
                for (int i = 0; i < height; ++i) {
                    vector<string> temp;
                    temp.resize(width);
                    for (int j = 0; j < width; ++j) {
                        temp[j] = frames[i][j];
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
