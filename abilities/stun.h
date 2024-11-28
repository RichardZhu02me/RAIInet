#ifndef STUN_H
#define STUN_H

#include "../ability.h"

using namespace std;

class Stun: public Ability {
    virtual bool Effect(Cell& target) override;
public:
    Stun(Player& caster);
};

#endif