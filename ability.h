#ifndef ABILITY_H
#define ABILITY_H

#include "cell.h"
#include <string>
#include <map>

using namespace std;

class Player;

class Ability {
protected:
    string name;
    Player& getCaster() const;
private:
    virtual bool Effect(Cell& target)=0;
    bool available;
    Player* caster;
public:
    Ability(Player& caster);
    virtual bool cast(Cell& target);
    static const map<char, string> abilityLibrary;

    bool getAvailable() const;
    void setUnavailable();
    string getName() const;
};

#endif