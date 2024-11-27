#ifndef FIREWALL_H
#define FIREWALL_H

#include "../ability.h"

class Firewall: public Ability {
    virtual bool Effect(Player& player, Game::Cell& target) override;
public:
};

#endif