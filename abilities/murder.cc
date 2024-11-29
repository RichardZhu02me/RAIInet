#include "murder.h"
#include "../player.h"
using namespace std;

Murder::Murder(Player& caster) 
    : Ability(caster) {
    name = "Murder";  // Use appropriate ID for Murder ability
}

bool Murder::Effect(Cell& target, bool debug) {
    if (target.link == nullptr || target.link->getOwnerId() == getCaster().getPlayerNum()) {
        if (debug) cout << "TARGET HAS NO LINK OR IS NOT OWNED BY THE CASTER!" << endl;
        return false;
    }
    // Implement murder effect here
    return true;
}