#include "polarize.h"
#include <string>

using namespace std;

bool Polarize::Effect(Player& player, Game::Cell& target) {
    if (target.link == nullptr) {
        return false;
    }
    target.link->changeType();
    return true;
}

string Polarize::getName() {
    return "Polarize";
}
