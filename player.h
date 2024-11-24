#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <memory>
#include "link.h"

using namespace std;


class Player{
    int numOfDataDownloaded = 0;
    int numOfVirusDownloaded = 0;
    int playerNum;
    int unusedAbilities;
public:
    // currently for basic player
    vector<Link*> links;
    vector<Link*> downloaded;
    Player(string abilityOrder, string linkOrder, int number);
    ~Player();
    void dataDownload(Link* link);
    void virusDownload(Link* link);
    bool isWon();
    void up();
    void down();
    void left();
    void right();
    void setLinks();
    //setupFirewall
    void setAbilities();
};
#endif
