#include "polarize.h"
#include "../player.h"
using namespace std;

Polarize::Polarize(Player& caster) 
    : Ability(caster) {
    name = "Polarize";
}

bool Polarize::Effect(Cell& target) {
    if (target.link == nullptr) {
        return false;
    }
    target.link->changeType();
    return true;
}

