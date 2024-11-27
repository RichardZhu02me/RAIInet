#include "polarize.h"

bool Polarize::Effect(Player& player, Game::Cell& target) {
    if (target.link == nullptr) {
        return false;
    }
    target.link->changeType();
    return true;
}