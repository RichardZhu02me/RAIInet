#ifndef MURDER_H
#define MURDER_H

#include "../ability.h"
#include "../game.h"  // Add this include


using namespace std;

class Murder: public Ability {
    //kill the target in the cell if there is a player's link nearby
    bool Effect(Cell& target, bool debug=false) override;
public:
    Murder(Player& caster);
    ~Murder() override = default;
};

#endif