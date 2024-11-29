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
    //the name of the ability
    string name;
    //get the caster of the ability
    Player& getCaster() const;
    //the effect of the ability
    virtual bool Effect(Cell& target, bool debug=false) = 0;
private:
    //whether the ability is available to be cast
    bool available;
    //the player that cast the ability
    Player* caster;
public:
    //constructor for the ability
    Ability(Player& caster);
    //casts the ability
    virtual bool cast(Cell& target, bool debug=false);
    //the library of abilities
    static const map<char, string> abilityLibrary;
    //destructor for the ability
    virtual ~Ability() = 0;

    //get whether the ability is available to be cast
    bool getAvailable() const;
    //set the ability to be unavailable
    void setUnavailable();
    //get the name of the ability
    string getName() const;
};

#endif
