#include "steal.h"
#include "../player.h"
#include <random>
#include <string>

using namespace std;

Steal::Steal(Player& caster) 
    : Ability(caster) {
    name = "Steal";
}

bool Steal::Effect(Cell& target, bool debug) {
    //if there is no link or the link is owned by the player return false
    if (target.link == nullptr || target.link->getOwnerId() == getCaster().getPlayerNum()) {
        if (debug) cout << "TARGET HAS NO LINK OR IS OWNED BY THE CASTER!" << endl;
        return false;
    }
    // target.link->setOwner(getCaster());
    // currently functionless
    return true;
}
