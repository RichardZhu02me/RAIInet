#ifndef LINKBOOST_H
#define LINKBOOST_H

#include "../ability.h"

using namespace std;

class LinkBoost: public Ability {
protected:
    bool Effect(Cell& target, bool debug=false) override;
public:
    LinkBoost(Player& caster);
    ~LinkBoost() override = default;
};

#endif
