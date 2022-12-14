#include "bad_apple_pixmap_frames-min.h"
#include "display/video.h"
#include "display/graphicsobs.h"
#include "display/textobs.h"
#include "display/videostudio.h"

#include <memory>
#include <stdint.h>

using namespace std;

int main() {
    unique_ptr<Video> bad_apple = make_unique<Video>(bad_apple_frames, NUM_FRAMES, FRAME_HEIGHT, FRAME_WIDTH);
    unique_ptr<VideoStudio> videoStudio = make_unique<VideoStudio>(bad_apple.get());
    unique_ptr<TextObserver> textObs = make_unique<TextObserver>(videoStudio.get());
    unique_ptr<GraphicsObs> graphicsObs = make_unique<GraphicsObs>(videoStudio.get(), FRAME_WIDTH, FRAME_HEIGHT);
    for (uint64_t i = 0; i < NUM_FRAMES; ++i) {
        videoStudio->notifyObservers();
        ++(*bad_apple);
    }
    return 0;
}
