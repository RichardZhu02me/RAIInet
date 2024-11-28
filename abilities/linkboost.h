#ifndef LINKBOOST_H
#define LINKBOOST_H

#include "../ability.h"

using namespace std;

class LinkBoost: public Ability {
    virtual bool Effect(Cell& target) override;
public:
    LinkBoost(Player& caster);
};

#endif