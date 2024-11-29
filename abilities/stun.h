#ifndef STUN_H
#define STUN_H

#include "../ability.h"

using namespace std;

class Stun: public Ability {
    bool Effect(Cell& target, bool debug=false) override;
public:
    Stun(Player& caster);
    ~Stun() override = default;
};

#endif