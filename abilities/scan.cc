#include "scan.h"

bool Scan::Effect(Player& player, Grid::Cell& target) {
    //if there is no link or the link is owned by the player return false
    if (target.link == nullptr || target.link->getOwner() == &player) {
        return false;
    }
    // do we want to reveal the link to the grid or the player?
    target.link->reveal();
    return true;
}