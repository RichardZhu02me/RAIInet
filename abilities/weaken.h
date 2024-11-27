#ifndef SCAN_H
#define SCAN_H

#include "../ability.h"
#include <string>

using namespace std;

class Weaken: public Ability {
    virtual bool Effect(Player& player, Game::Cell& target) override;
public:
    string getName() override;
};

#endif