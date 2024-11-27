#include "ability.h"

using namespace std;


//cast the ability on the target cell
//return true if the ability was cast successfully
//return false otherwise
bool Ability::cast(Player& player, Game::Cell& target) {
    if(Effect(player, target)) return true;
    return false;
}

bool getAvailable() const {
    return Available;
}

void setUnavailable() {
    Available = false;
}

size_t getId() {
    return id;
}
