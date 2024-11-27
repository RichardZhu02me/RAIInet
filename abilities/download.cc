#include "download.h"
#include <string>

using namespace std;

bool Download::Effect(Player& player, Game::Cell& target) {
    if (target.link == nullptr) {
        return false;
    }
    player.download(target.link);
    return true;
}

string Download::getName() {
    return "Download";
}
