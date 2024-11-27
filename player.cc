 #include "player.h"
 #include <iostream>
 using namespace std;

Player::Player(int number) : downloadedData{0},downloadedViruses{0},availableAbilities{0},playerNum{number} {}

Player::~Player(){}

void Player::notifyWin() const {
    game->win(playerNum);
}

void Player::notifyLoss() const {
    //fix
    game->loss(playerNum);
}

void Player::download(bool isData) {
    if (isData) {
        downloadedData++;
    } else {
        downloadedViruses++;
    }
}

bool Player::isHidden(int linkIndex) const {
    if (linkIndex < 0 || linkIndex >= static_cast<int>(links.size())) {
        return false;
    }
    return !links[linkIndex]->isRevealed();
}

void Player::customizeLinks(const std::vector<std::string>& linkDescriptions) {
    links.clear();
    for (const auto& desc : linkDescriptions) {
        char type = desc[0];
        int strength = desc[1] - '0';
        std::string linkType = (type == 'D') ? "data" : "virus";
        links.emplace_back(std::make_unique<Link>(linkType, strength));
    }
}

const std::vector<std::unique_ptr<Link>>& Player::getLinks() const {
    return links;
}

int Player::getPlayerNum(){
    return playerNum;
}

int Player::getNumOfDataDld(){
    return downloadedData;
}

int Player::getNumOfVirusDld(){
    return downloadedViruses;
}

int Player::addNumOfDataDld(){
    return downloadedData += 1;
}

int Player::addNumOfVirusDld(){
    return downloadedViruses += 1;
}

Ability* Player::getAbility(string ability) {
    for (auto& a : abilities) {
        if (typeid(*a).name() == ability) {
            return a.get();
        }
    }
    return nullptr;
}

void Player::removeAbility(Ability* ability) {
    for (auto& a : abilities) {
        if (a.get() == ability) {
            abilities.erase(std::remove(abilities.begin(), abilities.end(), a), abilities.end());
            break;
        }
    }
}
/*
//getter functions
int Player::getPlayerNum(){
    return playerNum;
}
int Player::getNumOfDataDld(){
    return numOfDataDld;
}
int Player::getNumOfVirusDld(){
    return numOfVirusDld;
}
int Player::getNumOfAbLeft(){
    return getNumOfAbLeft;
}
int Player::getNumFireWall(){
    return getNumFireWall;
}
int Player::getNumLinkBoost(){
    return getNumLinkBoost;
}
int Player::getNumDownload(){
    return getNumDownload;
}
int Player::getNumPolarize(){
    return getNumPolarize;
}
int Player::getNumScan(){
    return getNumScan;
}

//setter functions
int Player::setPlayerNum(int x){
    return playerNum = x;
}
int Player::addNumOfDataDld(){
    return numOfDataDld += 1;
}
int Player::addNumOfVirusDld(){
    return numOfVirusDld += 1;
}
int Player::setNumOfAbLeft(int x){
    return numOfAbLeft = x;
}

void Player::download(Link* link);
void Player::notifyWin();
bool Player::isHidden();
void Player::customizeLinks();

void Player::setLink();

void Player::setAbility(string ability){
    if (ability == "download") {
        numDownload += 1;
    }
    if (ability == "linkboost") {
        numLinkBoost += 1;
    }
    if (ability == "firewall") {
        numFirewall += 1;
    }
    if (ability == "polarize") {
        numPolarize += 1;
    }
    if (ability == "scan") {
        numScan += 1;
    }
}
*/
