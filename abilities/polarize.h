#ifndef POLARIZE_H
#define POLARIZE_H

#include "../ability.h"
#include "../game.h"  // Add this include

using namespace std;

class Polarize: public Ability {
    virtual bool Effect(Cell& target) override;
public:
    Polarize(Player& caster);   
};

#endif