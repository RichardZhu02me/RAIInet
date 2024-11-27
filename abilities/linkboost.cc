#include "linkboost.h"

bool LinkBoost::Effect(Player& player, Game::Cell& target) {
    if (target.link == nullptr) {
        return false;
    }
    target.link->boost();
    return true;
}  