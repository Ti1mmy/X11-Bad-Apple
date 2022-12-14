#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include <vector>
#include <string>
#include "observer.h"

class Observer;

class Subject {
        std::vector<Observer*> observers;
    public:
        void attach(Observer *o);
        void detach(Observer *o);
        void notifyObservers();
        virtual const std::vector<std::string>& getState() const = 0;
        virtual ~Subject() = default;
};

#endif
