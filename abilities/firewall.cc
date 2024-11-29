#include "firewall.h"
#include "../build.h"
#include "../player.h"
#include <iostream>
using namespace std;

Firewall::Firewall(Player& caster) 
    : Ability(caster) {
    name = "Firewall";
}   

bool Firewall::Effect(Cell& target, bool debug) {
    if (target.link != nullptr) {
        if (debug) cout << "TARGET HAS A LINK!" << endl;
        return false;
    }
    //if there is already a build on the cell return false
    if (target.build != nullptr) {
        cout << "CELL ALREADY HAS A BUILD!" << endl;
        return false;
    }
    //set the build on the cell
    target.build = Build::buildFirewall(getCaster().getPlayerNum());
    target.firewall = true;
    return true;
}

