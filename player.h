#ifndef player_H
#define player_H

#include "link.h"
#include <vector>

class Player{
    std::vector<Link*> links;
public:
    void download(Link* link);
};
#endif