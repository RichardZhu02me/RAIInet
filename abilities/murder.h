#ifndef SCAN_H
#define SCAN_H

#include "../ability.h"
#include <string>

using namespace std;

class Murder: public Ability {
    //kill the target in the cell if there is a player's link nearby
    virtual bool Effect(Player& player, Game::Cell& target) override;
public:
    string getName() override;
};

#endif