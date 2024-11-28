#include "ability.h"
#include "cell.h"
#include "player.h"
using namespace std;

Ability::Ability(Player& caster): id(0), available(true), caster(&caster) {}

//cast the ability on the target cell
//return true if the ability was cast successfully
//return false otherwise
bool Ability::cast(Cell& target) {
    if(Effect(target)) return true;
    return false;
}

bool Ability::getAvailable() const {
    return available;
}

void Ability::setUnavailable() {
    available = false;
}

Player& Ability::getCaster() const {
    return *caster;
}

const map<int, string> Ability::abilityLibrary = {
    {1, "Link Boost"},
    {2, "Scan"},
    {3, "Download"},
    {4, "Firewall"},
    {5, "Polarity"},
    {6, "Steal"}, // steal is not implemented, will steal an opponent's link
    {7, "Stun"}, // stun is not implemented, will stop an opponent from moving the unit for two turns
    {8, "Weaken"}, 
};

int Ability::getId() const {
    return id;
}
