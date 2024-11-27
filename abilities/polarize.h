#ifndef POLARIZE_H
#define POLARIZE_H

#include "../ability.h"
#include <string>

using namespace std;

class Polarize: public Ability {
    virtual bool Effect(Player& player, Game::Cell& target) override;
public:
    string getName() override;
};

#endif