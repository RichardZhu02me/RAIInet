#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "observer.h"
#include <memory>
class Subject {
  std::vector<std::unique_ptr<Observer>> observers;
 public:
  void attach( Observer* o );
  void detach( Observer* o );
  void notifyObservers();
  virtual char getState( size_t row, size_t col ) const = 0;
  virtual ~Subject();
};

#endif
