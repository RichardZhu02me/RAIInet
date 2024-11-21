#include "polarize.h"

bool Polarize::Effect(Player& player, Grid::Cell& target) {
    if (target.link == nullptr) {
        return false;
    }
    target.link->polarize();
    return true;
}