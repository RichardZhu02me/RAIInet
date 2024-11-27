#include "linkboost.h"
#include <string>

using namespace std;

bool LinkBoost::Effect(Player& player, Game::Cell& target) {
    if (target.link == nullptr) {
        return false;
    }
    target.link->boost();
    return true;
} 

string LinkBoost::getName() {
    return "linkboost";
}
