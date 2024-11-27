#include "subject.h"
#include "observer.h"
#include <vector>

void Subject::attach( Observer* o ) {
    observers.push_back(o);
}

void Subject::detach( Observer* o ) {
    for (auto it = observers.begin(); it != observers.end();) {
        if (*it == o) {
            delete *it;
            it = observers.erase(it);
        } else {
            ++it;
        }
    }
}

void Subject::notifyObservers() {
    for (Observer* o : observers) {
        o->notify();
    }
}

Subject::~Subject() {
    for (auto it = observers.begin(); it != observers.end();) {
        delete *it;
        it = observers.erase(it);
    }
}
