#include "steal.h"
#include "../player.h"
#include <random>
#include <string>

using namespace std;

Steal::Steal(Player& caster) 
    : Ability(caster) {
    id = 6;
}

bool Steal::Effect(Cell& target) {
    //if there is no link or the link is owned by the player return false
    if (target.link == nullptr || target.link->getOwnerId() == getCaster().getPlayerNum()) {
        return false;
    }
    // target.link->setOwner(getCaster());
    // currently functionless
    return true;
}
