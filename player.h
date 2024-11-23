#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <memory>
#include "link.h"

using namespace std;


class Player{
    vector<Link*> links;
    int numOfDataDld = 0;
    int numOfVirusDld = 0;
    int playerNum;
    int unusedAbilities;
public:
    // currently for basic player
    Player(string abilityOrder, string linkOrder, int number);
    ~Player();
    void download(Link* link);
};
#endif
