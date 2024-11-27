#ifndef FIREWALL_H
#define FIREWALL_H

#include "../ability.h"
#include <string>

using namespace std;


class Firewall: public Ability {
    virtual bool Effect(Player& player, Game::Cell& target) override;
public:
    string getName() override;
};
#endif