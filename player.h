#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <memory>
#include "link.h"
#include "grid.h"

using namespace std;


class Player{
    int playerNum;
    int numOfDataDld = 0; //number of data downloaded
    int numOfVirusDld = 0; //number of virus downloaded
    int numOfAbLeft = 0; //number of abilities left
    int numFireWall = 0;
    int numLinkBoost = 0;
    int numDownload = 0;
    int numPolarize = 0;
    int numScan = 0;
public:
    // currently for basic player
    vector<shared_ptr<Link>> links;
    Player(int number);
    ~Player();

    //getter functions
    int getPlayerNum();
    int getNumOfDataDld();
    int getNumOfVirusDld();
    int getNumOfAbLeft();
    int getNumFireWall();
    int getNumLinkBoost();
    int getNumDownload();
    int getNumPolarize();
    int getNumScan();

    //setter functions
    int setPlayerNum();
    int setNumOfDataDld();
    int setNumOfVirusDld();
    int setNumOfAbLeft();

    void download(Link* link);
    void notifyWin();
    bool isHidden();
    void customizeLinks();
    //setupFirewall
    void setLink();
    void setAbilities(string ability);
};
#endif
