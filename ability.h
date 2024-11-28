#ifndef ABILITY_H
#define ABILITY_H

#include "cell.h"
#include <string>
#include <map>

using namespace std;

class Player;

class Ability {
protected:
    int id;
    Player& getCaster() const;
private:
    virtual bool Effect(Cell& target)=0;
    bool available;
    Player* caster;
public:
    Ability(Player& caster);
    virtual bool cast(Cell& target);
    const static map<int, string> abilityLibrary;

    bool getAvailable() const;
    void setUnavailable();
    int getId() const;
};

#endif