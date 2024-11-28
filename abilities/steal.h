#ifndef STEAL_H
#define STEAL_H

#include "../ability.h"

using namespace std;

class Steal: public Ability {
    virtual bool Effect(Cell& target) override;
public:
    Steal(Player& caster);
};

#endif