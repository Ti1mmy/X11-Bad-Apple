#include "videostudio.h"

using namespace std;

VideoStudio::VideoStudio(Video* v): video{v} {}

int VideoStudio::getFrameNum() { return video->frameNum(); }

const vector<string> &getCurrentFrame() { return video->getCurrentFrame(); }
