#ifndef PLAYER_H
#define PLAYER_H

#include "Link.h"
#include <vector>
#include <memory>
#include <string>

class Player {
    std::vector<std::unique_ptr<Link>> links;
    int downloadedData;
    int downloadedViruses;
    int availableAbilities;

public:
    Player();
    void notifyWin() const;
    void download(bool isData);
    bool isHidden(int linkIndex) const;
    void customizeLinks(const std::vector<std::string>& linkDescriptions);
    const std::vector<std::unique_ptr<Link>>& getLinks() const;
    int getPlayerNum();
    int getNumOfDataDld();
    int getNumOfVirusDld();
    int addNumOfDataDld();
    int addNumOfVirusDld();

};

#endif // PLAYER_H
