#ifndef LINKBOOST_H
#define LINKBOOST_H

#include "../ability.h"

class LinkBoost: public Ability {
    virtual bool Effect(Player& player, Grid::Cell& target) override;
public:
};

#endif