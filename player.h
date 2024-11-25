#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <memory>
#include "link.h"
#included "grid.h"

using namespace std;


class Player{
    int playerNum;
    int numOfDataDownloaded = 0;
    int numOfVirusDownloaded = 0;
public:
    // currently for basic player
    vector<shared_ptr<Ability>> abilities;
    vector<shared_ptr<Link>> links;
    vector<shared_ptr<Link>> downloaded;
    Player(string abilityOrder, string linkOrder, int number);
    ~Player();
    void download(Link* link);
    void notifyWin();
    bool isHidden();
    void customizeLinks();
    //setupFirewall
    void setLink();
    void setAbilities();
};
#endif
