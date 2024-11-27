#include "download.h"


bool Download::Effect(Player& player, Game::Cell& target) {
    if (target.link == nullptr) {
        return false;
    }
    player.download(target.link);
    return true;
}