#ifndef ABILITY_H
#define ABILITY_H

#include "cell.h"
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Player;

class Ability {
protected:
    string name;
    Player& getCaster() const;
    virtual bool Effect(Cell& target, bool debug=false) = 0;
private:
    bool available;
    Player* caster;
public:
    Ability(Player& caster);
    virtual bool cast(Cell& target, bool debug=false);
    static const map<char, string> abilityLibrary;
    virtual ~Ability() = 0;

    bool getAvailable() const;
    void setUnavailable();
    string getName() const;
};

#endif