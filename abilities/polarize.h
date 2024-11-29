#ifndef POLARIZE_H
#define POLARIZE_H

#include "../ability.h"
#include "../game.h"  // Add this include

using namespace std;

class Polarize: public Ability {
    bool Effect(Cell& target, bool debug=false) override;
public:
    Polarize(Player& caster);   
    ~Polarize() override = default;
};

#endif