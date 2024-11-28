#include "firewall.h"
#include "../build.h"
#include "../player.h"
using namespace std;

Firewall::Firewall(Player& caster) 
    : Ability(caster) {
    id = 3;
}   

bool Firewall::Effect(Cell& target) {
    if (target.link != nullptr) {
        return false;
    }
    //if there is already a build on the cell return false
    if (target.build != nullptr) {
        return false;
    }
    //set the build on the cell
    target.build = Build::buildFirewall(getCaster().getPlayerNum());
    return true;
}

