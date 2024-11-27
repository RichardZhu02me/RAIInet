#include "firewall.h"
#include <string>

using namespace std;

bool Firewall::Effect(Player& player, Game::Cell& target) {
    if (target.link != nullptr) {
        return false;
    }
    //if there is already a build on the cell return false
    if (target.build != nullptr) {
        return false;
    }
    //set the build on the cell
    target.build = Game::Build::buildFirewall(player);
    return true;
}

string Firewall::getName() {
    return "firewall";
}
