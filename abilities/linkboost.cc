#include "linkboost.h"

bool LinkBoost::Effect(Player& player, Grid::Cell& target) {
    if (target.link == nullptr) {
        return false;
    }
    target.link->boost();
    return true;
}  