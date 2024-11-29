#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <memory>
#include <string>
#include "link.h"

class Ability;

using namespace std;

class Player {
    vector<unique_ptr<Link>> links;
    vector<unique_ptr<Ability>> abilities;
    int playerNum;
    int downloadedData;
    int downloadedViruses;
    int availableAbilities;
    // Player* opponent; // pointer to the opponent (for steal)

public:
    Player(int number);
    ~Player();
    void download(bool isData);
    bool isHidden(int linkIndex) const;
    const std::vector<std::unique_ptr<Link>>& getLinks() const;
    int getPlayerNum();
    int getNumOfAbLeft();
    int getNumOfDataDld();
    int getNumOfVirusDld();
    int addNumOfDataDld();
    int addNumOfVirusDld();

    Link& getPlLink(size_t id);
    Ability& getAbility(size_t abId);    
    bool addAbility(char c);
    void setLink(char type, int strength, char symbol);
    // void setOpponent(Player& opp);
};

#endif // PLAYER_H
