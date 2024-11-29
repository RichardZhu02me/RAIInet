#ifndef SCAN_H
#define SCAN_H

#include "../ability.h"
#include "../game.h"  // Add this include


using namespace std;

class Scan: public Ability {
    bool Effect(Cell& target, bool debug=false) override;
public:
    Scan(Player& caster);
    ~Scan() override = default;
};

#endif
