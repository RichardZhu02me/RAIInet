#include "download.h"
#include "../player.h"
using namespace std;

Download::Download(Player& caster) 
    : Ability(caster) {
    id = 4;
}

bool Download::Effect(Cell& target) {
    if (target.link == nullptr) {
        return false;
    }
    getCaster().download(target.link);
    return true;
}

