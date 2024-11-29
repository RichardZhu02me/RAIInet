#ifndef FIREWALL_H
#define FIREWALL_H

#include "../ability.h"

using namespace std;


class Firewall: public Ability {
    bool Effect(Cell& target) override;
public:
    Firewall(Player& caster);
};
#endif