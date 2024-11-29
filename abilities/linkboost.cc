#include "linkboost.h"
#include "../player.h"
#include <iostream>
using namespace std;

LinkBoost::LinkBoost(Player& caster) 
    : Ability(caster) {
    name = "Link Boost";
}   

bool LinkBoost::Effect(Cell& target, bool debug) {
    cout << "LINKBOOST EFFECT" << endl;
    if (debug) cout << target.link->getSymbol() << endl;
    if (target.link) {
        target.link->boost();
        if (debug) cout << "BOOSTING LINK!" << endl;
        return true;
    }
    if (debug) cout << "TARGET HAS NO LINK!" << endl;
    return false;
   
} 
