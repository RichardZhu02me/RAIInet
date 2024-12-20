#include "stun.h"
#include "../player.h"
using namespace std;

Stun::Stun(Player& caster) 
    : Ability(caster) {
    name = "Stun";
}

bool Stun::Effect(Cell& target, bool debug) {
    if (target.link == nullptr || target.link->getOwnerId() == getCaster().getPlayerNum()) {
        if (debug) cout << "TARGET HAS NO LINK OR IS OWNED BY THE CASTER!" << endl;
        return false;
    }
    if (debug) cout << "STUNNING TARGET" << endl;
    target.link->setStunned(3);
    if (debug) cout << "TARGET STUNNED" << endl;
    return true;
}
