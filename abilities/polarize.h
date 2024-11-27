#ifndef POLARIZE_H
#define POLARIZE_H

#include "../ability.h"

class Polarize: public Ability {
    virtual bool Effect(Player& player, Game::Cell& target) override;
public:
};

#endif