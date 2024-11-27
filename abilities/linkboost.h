#ifndef LINKBOOST_H
#define LINKBOOST_H

#include "../ability.h"
#include <string>

using namespace std;

class LinkBoost: public Ability {
    virtual bool Effect(Player& player, Game::Cell& target) override;
public:
    string getName() override;
};

#endif