#ifndef WEAKEN_H
#define WEAKEN_H

#include "../ability.h"

using namespace std;


class Weaken: public Ability {
    bool Effect(Cell& target) override;
public:
    Weaken(Player& caster);
};

#endif