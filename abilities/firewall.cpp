#include "firewall.h"


bool Firewall::Effect(Player& player, Grid::Cell& target) {
    if (target.link != nullptr) {
        return false;
    }
    //if there is already a build on the cell return false
    if (target.build != nullptr) {
        return false;
    }
    //set the build on the cell
    target.build = Grid::Build::buildFirewall(player);
    return true;
}