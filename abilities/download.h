#ifndef DOWNLOAD_H
#define DOWNLOAD_H     

#include "../ability.h"

using namespace std;


class Download: public Ability {
    bool Effect(Cell& target) override;
public:
    Download(Player& caster);
};

#endif