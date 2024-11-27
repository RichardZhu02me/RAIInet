#ifndef PLAYER_H
#define PLAYER_H

#include "Link.h"
#include <vector>
#include <memory>
#include <string>
#include "ability.h"

class Player {
    std::vector<std::unique_ptr<Link>> links;
    std::vector<std::unique_ptr<Ability>> abilities;
    int playerNum;
    int downloadedData;
    int downloadedViruses;
    int availableAbilities;
    Game* game;

public:
    Player(int number);
    ~Player();
    void notifyWin() const;
    void notifyLoss() const;
    void download(bool isData);
    bool isHidden(int linkIndex) const;
    void customizeLinks(const std::vector<std::string>& linkDescriptions);
    const std::vector<std::unique_ptr<Link>>& getLinks() const;
    int getPlayerNum();
    int getNumOfAbLeft();
    int getNumOfDataDld();
    int getNumOfVirusDld();
    int addNumOfDataDld();
    int addNumOfVirusDld();

    Link& getPlLink(size_t id);
    Ability* getAbility(string ability);    
    void removeAbility(Ability* ability);
    void addAbility(char ability, size_t id);
    void setLink(char type, int strength, char symbol);
};

#endif // PLAYER_H
