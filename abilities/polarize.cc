#include "polarize.h"
#include "../player.h"
using namespace std;

Polarize::Polarize(Player& caster) 
    : Ability(caster) {
    name = "Polarize";
}

bool Polarize::Effect(Cell& target, bool debug) {
    if (target.link == nullptr) {
        if (debug) cout << "TARGET HAS NO LINK!" << endl;
        return false;
    }
    target.link->changeType();
    return true;
}

