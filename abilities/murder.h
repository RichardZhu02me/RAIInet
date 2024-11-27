#ifndef SCAN_H
#define SCAN_H

#include "../ability.h"

class Murder: public Ability {
    //kill the target in the cell if there is a player's link nearby
    virtual bool Effect(Player& player, Game::Cell& target) override;
public:
};

#endif