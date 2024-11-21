#include "download.h"


bool Download::Effect(Player& player, Grid::Cell& target) {
    if (target.link == nullptr) {
        return false;
    }
    player.download(target.link);
    return true;
}