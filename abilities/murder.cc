#include "murder.h"
#include "../player.h"
using namespace std;

Murder::Murder(Player& caster) 
    : Ability(caster) {
    id = 9;  // Use appropriate ID for Murder ability
}

bool Murder::Effect(Cell& target) {
    if (target.link == nullptr || target.link->getOwnerId() == getCaster().getPlayerNum()) {
        return false;
    }
    // Implement murder effect here
    return true;
}