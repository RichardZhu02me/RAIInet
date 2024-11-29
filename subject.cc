#include "subject.h"
#include <vector>

void Subject::attach( Observer* o ) {
    observers.push_back(std::unique_ptr<Observer>(o));
}

void Subject::detach( Observer* o ) {
    for (auto it = observers.begin(); it != observers.end();) {
        if (it->get() == o) {
            it = observers.erase(it);
        } else {
            ++it;
        }
    }
}

void Subject::notifyObservers() {
    for (auto& o : observers) {
        o->notify();
    }
}

Subject::~Subject() {
    for (auto it = observers.begin(); it != observers.end();) {
        it = observers.erase(it);
    }
}
