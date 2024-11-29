#include "download.h"
#include "../player.h"
#include "../game.h"
using namespace std;

Download::Download(Player& caster) 
    : Ability(caster) {
    name = "Download";
}

bool Download::Effect(Cell& target, bool debug) {
    if (target.link == nullptr) {
        if (debug) cout << "TARGET HAS NO LINK!" << endl;
        return false;
    }
    getCaster().download(target.link);
    target.link->deactivate();
    target.link = nullptr;
    if (debug) cout << "DOWNLOAD SUCCESSFUL" << endl;
    return true;
}

