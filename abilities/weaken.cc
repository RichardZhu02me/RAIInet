#include "weaken.h"
#include "../player.h"
#include <random>

Weaken::Weaken(Player& caster) 
    : Ability(caster) {
    name = "Weaken";
}

bool Weaken::Effect(Cell& target) {
    //if there is no link or the link is owned by the player return false
    if (target.link == nullptr || target.link->getOwnerId() == getCaster().getPlayerNum()) {
        return false;
    }
    int random = rand() % 4 + 1;
    // do we want to reveal the link to the Game or the player?
    target.link->weaken(random);
    return true;
}
