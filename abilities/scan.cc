#include "scan.h"
#include "../player.h"
using namespace std;

Scan::Scan(Player& caster) 
    : Ability(caster) {
    name = "Scan";
}

bool Scan::Effect(Cell& target) {
    //if there is no link or the link is owned by the player return false
    if (target.link == nullptr || target.link->getOwnerId() == getCaster().getPlayerNum()) {
        return false;
    }
    // do we want to reveal the link to the Game or the player?
    target.link->reveal();
    return true;
}

