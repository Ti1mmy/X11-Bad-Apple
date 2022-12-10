#include "video.h"
using namespace std;

Video::Video(const colour &frames[NUM_FRAMES_H][FRAME_HEIGHT_H][FRAME_WIDTH_H], int numFrames, int height, int width):
            frameWidth{width}, frameHeight{height}, currentFrame{0} {
                for (int i = 0; i < numFrames; ++i) {
                    vector<colour> temp1;
                    for (int j = 0; j < height; ++j) {
                        vector<colour> temp2;
                        for (int k = 0; k < width; ++k) {
                            temp2.emplace_back(frames[i][j][k]);
                        }
                        temp1.emplace_back(move(temp2));
                    }
                    frameList.emplace_back(move(temp1));
                }
            }

int Video::getFrameWidth() const { return frameWidth; }

int Video::getFrameHeight() const { return frameHeight; }

int Video::frameNum() const { return currentFrame; }

const vector<vector<colour>>& Video::getCurrentFrame() const { return frameList[currentFrame]; }

Video& Video::operator++() {
    ++currentFrame;
    return *this;
}
