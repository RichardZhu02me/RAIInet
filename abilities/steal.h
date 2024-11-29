#ifndef STEAL_H
#define STEAL_H

#include "../ability.h"

using namespace std;

class Steal: public Ability {
    bool Effect(Cell& target, bool debug=false) override;
public: 
    Steal(Player& caster);
    ~Steal() override = default;
};

#endif