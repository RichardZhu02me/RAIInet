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
    //updates the number of data or viruses downloaded
    void download(bool isData);
    //checks if the link is hidden
    bool isHidden(int linkIndex) const;
    //returns the links
    const std::vector<std::unique_ptr<Link>>& getLinks() const;
    //returns the player number
    int getPlayerNum();
    //returns the number of abilities left
    int getNumOfAbLeft();
    //returns the number of data downloaded
    int getNumOfDataDld();
    //returns the number of viruses downloaded
    int getNumOfVirusDld();
    //adds the number of data downloaded
    int addNumOfDataDld();
    //adds the number of viruses downloaded
    int addNumOfVirusDld();
    //returns the link at the given index
    Link& getPlLink(size_t id);
    //returns the ability at the given index
    Ability& getAbility(size_t abId);    
    //adds an ability with the given symbol c to the player
    bool addAbility(char c);
    //sets the link's type, strength, and symbol
    void setLink(char type, int strength, char symbol);
    // void setOpponent(Player& opp);
};

#endif // PLAYER_H
