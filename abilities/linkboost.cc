#include "linkboost.h"
#include "../player.h"
using namespace std;

LinkBoost::LinkBoost(Player& caster) 
    : Ability(caster) {
    id = 1;
}   

bool LinkBoost::Effect(Cell& target) {
    if (target.link == nullptr) {
        return false;
    }
    target.link->boost();
    return true;
} 
