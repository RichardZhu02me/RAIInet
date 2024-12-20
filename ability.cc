#include "ability.h"
#include "cell.h"
#include "player.h"
#include <iostream>
using namespace std;

Ability::Ability(Player& caster): available(true), caster(&caster) {}

//cast the ability on the target cell
//return true if the ability was cast successfully and makes the ability unavailable to cast
//return false otherwise
bool Ability::cast(Cell& target, bool debug) {
    // if (debug) cout << "ABILITY AVAILABLE: " << getAvailable() << endl;
    // if (debug) cout << "TARGET'S LINK: " << target.link->getSymbol() << endl;
    // if (debug) cout << "TARGET'S BUILD: " << target.build << endl;
    if (debug) cout << "ABILITY NAME: " << getName() << endl;
    if (!getAvailable()) return false;
    if (debug) cout << "EFFECTING TARGET" << endl;
    bool success = Effect(target, debug);
    if (debug) cout << "EFFECT SUCCESSFUL: " << success << endl;
    if(success) {
        setUnavailable();
        return true;
    } 
    return false;
}

//destructor for the ability
Ability::~Ability() = default;

//get whether the ability is available to be cast
bool Ability::getAvailable() const {
    return available;
}
//set the ability to be unavailable
void Ability::setUnavailable() {
    available = false;
}

//get the caster of the ability
Player& Ability::getCaster() const {
    return *caster;
}

//the library of abilities
static const map<char, string> abilityLibrary = {
        {'L', "Link Boost"},
        {'S', "Scan"},
        {'D', "Download"},
        {'F', "Firewall"},
        {'P', "Polarity"},
        {'X', "Steal"}, // steal is not implemented, will steal an opponent's link
        {'C', "Stun"}, // stun is not implemented, will stop an opponent from moving the unit for two turns
        {'W', "Weaken"}, 
        {'M', "Murder"}
};


string Ability::getName() const {
    return name;
}
