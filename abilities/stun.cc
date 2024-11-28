#include "stun.h"
#include "../player.h"
using namespace std;

Stun::Stun(Player& caster) 
    : Ability(caster) {
    id = 7;
}

bool Stun::Effect(Cell& target) {
    if (target.link == nullptr || target.link->getOwnerId() == getCaster().getPlayerNum()) {
        return false;
    }
    // TODO: Implement stun effect
    return true;
} 