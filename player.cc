#include "player.h"
#include "ability.h"
#include "abilities/abilities.h"
#include <iostream>
using namespace std;

Player::Player(int number) : playerNum{number},downloadedData{0},downloadedViruses{0},availableAbilities{0} {}

Player::~Player(){}

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


void Player::setLink(char type, int strength, char symbol) {
    std::string linkType = (type == 'D') ? "data" : "virus";
    links.emplace_back(std::make_unique<Link>(linkType, strength, symbol, playerNum));
}

const std::vector<std::unique_ptr<Link>>& Player::getLinks() const {
    return links;
}

int Player::getPlayerNum(){
    return playerNum;
}

int Player::getNumOfAbLeft(){
    return availableAbilities;
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

Link& Player::getPlLink(size_t id) {
    return *links[id];
}


Ability& Player::getAbility(size_t id) {
    
    return *abilities[id];
}

bool Player::addAbility(int id) {
    unique_ptr<Ability> newAbility;
    switch (id) {
        case 1:
            newAbility = unique_ptr<Ability>(new LinkBoost(*this));
            abilities.push_back(std::move(newAbility));
            break;
        case 2:
            newAbility = unique_ptr<Ability>(new Scan(*this));
            abilities.push_back(std::move(newAbility));
            break;
        case 3:
            newAbility = unique_ptr<Ability>(new Download(*this));
            abilities.push_back(std::move(newAbility));
            break;  
        case 4:
            newAbility = unique_ptr<Ability>(new Firewall(*this));
            abilities.push_back(std::move(newAbility));
            break;
        case 5:
            newAbility = unique_ptr<Ability>(new Polarize(*this));
            abilities.push_back(std::move(newAbility));
            break;
        case 6: // Steal not implemented
            return false;
            newAbility = unique_ptr<Ability>(new Steal(*this));
            abilities.push_back(std::move(newAbility));
            break;
        case 7: // Stun not implemented
            return false;
            newAbility = unique_ptr<Ability>(new Stun(*this));
            abilities.push_back(std::move(newAbility));
            break;
        case 8: 
            newAbility = unique_ptr<Ability>(new Weaken(*this));
            abilities.push_back(std::move(newAbility));
            break;
        default:
            return false;
    }
    return true;
}

void Player::removeAbility(size_t abId) {
    abilities.erase(
        std::remove(abilities.begin(), abilities.end(), abilities[abId]),
        abilities.end()
    );
}
