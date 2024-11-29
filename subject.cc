#include "subject.h"
#include <vector>
#include <algorithm>

using namespace std;

void Subject::attach(std::unique_ptr<Observer> o) {
    observers.push_back(std::move(o));
}

void Subject::detach(Observer* o) {
    auto it = std::remove_if(observers.begin(), observers.end(),
                             [o](const unique_ptr<Observer>& observer) {
                                 return observer.get() == o; // Compare raw pointer
                             });
    observers.erase(it, observers.end()); // Erase the matching observer
}

void Subject::notifyObservers() {
    for (const auto& o : observers) { // Use const reference for unique_ptr
        o->notify();
    }
}

Subject::~Subject() {}
