#ifndef SCAN_H
#define SCAN_H

#include "../ability.h"

class Scan: public Ability {
    virtual bool Effect(Player& player, Game::Cell& target) override;
public:
};

#endif