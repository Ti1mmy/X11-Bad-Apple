#include "subject.h"
#include "observer.h"
// Subject

void Subject::attach(Observer *o) {
    observers.emplace_back(o);
}

void Subject::detach(Observer *o) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == o) {
            observers.erase(it);
            return;
        }
    }
}

void Subject::notifyObservers() {
    for (Observer* ob: observers) ob->notify();
}
