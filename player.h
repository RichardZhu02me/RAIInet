#ifndef player_H
#define player_H

#include "link.h"
#include <vector>
#include <memory>


class Player{
    std::vector<Link*> links;
public:
    // currently for basic player
    Player(std::string abilityOrder, std::string linkOrder, int number);
    ~Player();
    void download(Link* link);
};
#endif
