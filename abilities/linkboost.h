#ifndef LINKBOOST_H
#define LINKBOOST_H

#include "../ability.h"

class LinkBoost: public Ability {
    virtual bool Effect(Player& player, Game::Cell& target) override;
public:
};

#endif