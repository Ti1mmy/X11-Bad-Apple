#include "textobs.h"

using namespace std;

TextObserver::TextObserver(VideoStudio *v): v{v} {
    v->attach(this);
}
TextObserver::~TextObserver() { v->detach(this); }

TextObserver::notify() {
    out << "Display Frame: " << v->getFrameNum() << endl;
}
