#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <memory>
#include "observer.h"

using namespace std;

class Subject {
  vector<unique_ptr<Observer>> observers;
 public:
  void attach( unique_ptr<Observer> o );
  void detach( Observer* o );
  void notifyObservers();
  virtual char getState( size_t row, size_t col ) const = 0;
  virtual ~Subject();
};

#endif
