#ifndef DOWNLOAD_H
#define DOWNLOAD_H     

#include "../ability.h"

class Download: public Ability {
    virtual bool Effect(Player& player, Grid::Cell& target) override;
public:
};

#endif