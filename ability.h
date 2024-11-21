#ifndef ABILITY_H
#define ABILITY_H

#include "grid.h"
using namespace std;

class Ability {
private:
    //the effect of the ability
    //return true if the effect was applied successfully
    //return false otherwise    
   virtual bool Effect(Grid::Cell* target)=0;
public:
    //cast the ability on the target cell
    //return true if the ability was cast successfully
    //return false otherwise
    virtual bool cast(Grid::Cell* target);
};

#endif