#include "subject.h"
#include <vector>
#include <algorithm>

<<<<<<< HEAD
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
=======
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
>>>>>>> b741cdebbc603f2418c88221ad2b293115d086ce
        o->notify();
    }
}

<<<<<<< HEAD
Subject::~Subject() {
    for (auto it = observers.begin(); it != observers.end();) {
        it = observers.erase(it);
    }
}
=======
Subject::~Subject() {}
>>>>>>> b741cdebbc603f2418c88221ad2b293115d086ce
