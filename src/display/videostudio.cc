#include "videostudio.h"

using namespace std;

VideoStudio::VideoStudio(Video* v): video{v} {}

int VideoStudio::getFrameNum() const { return video->frameNum(); }

const vector<vector<colour>> &VideoStudio::getState() const { return video->getCurrentFrame(); }
