#include "bad_apple_pixmap_frames.h"
#include "video.h"
#include "graphicsobs.h"
#include "textobs.h"
#include "videostudio.h"

#include <memory>
#include <stdint>

using namespace std;

int main() {
    const uint64_t frame_count = bad_apple_frames.size();
    if (frame_count == 0) exit(1); // video must be non-empty
    unique_ptr<Video> bad_apple = make_unique<Video>(bad_apple_frames);
    unique_ptr<VideoStudio> videoStudio = make_unique<VideoStudio>(bad_apple.get());
    unique_ptr<TextObserver> textObs = make_unique<TextObserver>(videoStudio.get());
    unique_ptr<GraphicsObserver> graphicsObs = make_unique<GraphicsObserver>(videoStudio.get());
    for (uint64_t i = 0; i < frame_count; ++i) {
        videoStudio->notifyObservers();
        ++(*bad_apple);
    }
    return 0;
}