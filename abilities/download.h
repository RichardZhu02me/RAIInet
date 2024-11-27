#ifndef DOWNLOAD_H
#define DOWNLOAD_H     

#include "../ability.h"
#include <string>

using namespace std;


class Download: public Ability {
    virtual bool Effect(Player& player, Game::Cell& target) override;
    
public:
    string getName() override;
};

#endif