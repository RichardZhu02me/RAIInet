#ifndef SCAN_H
#define SCAN_H

#include "../ability.h"
#include "../game.h"  // Add this include


using namespace std;

class Scan: public Ability {
    virtual bool Effect(Cell& target) override;
public:
    Scan(Player& caster);
};

#endif