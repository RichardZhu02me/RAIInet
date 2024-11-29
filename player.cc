#include "player.h"
#include "ability.h"
#include "abilities/abilities.h"
#include <iostream>
using namespace std;

Player::Player(int number) : playerNum{number},downloadedData{0},downloadedViruses{0},availableAbilities{5} {

    cout << "CREATING PLAYER " << number << endl;
    // cout << "Number " << playerNum << endl;
    // char base = 'a';
    // setLink('V', 5 ,(base));
    playerNum = number;

    // Initiallize Links
}

Player::~Player(){}

void Player::download(bool isData) {
    if (isData) {
        downloadedData++;
        cout << "DOWNLOADED DATA, current data: " << downloadedData << endl;
    } else {
        downloadedViruses++;
        cout << "DOWNLOADED VIRUS, current viruses: " << downloadedViruses << endl;
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

bool Player::addAbility(char c) {
    // cout << "BRUH" << endl;
    // cout << downloadedViruses<< endl;
    unique_ptr<Ability> newAbility;
    switch (c) {
        case 'L':
            newAbility = unique_ptr<Ability>(new LinkBoost(*this));
            abilities.push_back(std::move(newAbility));
            break;
        case 'S':
            newAbility = unique_ptr<Ability>(new Scan(*this));
            abilities.push_back(std::move(newAbility));
            break;
        case 'D':
            newAbility = unique_ptr<Ability>(new Download(*this));
            abilities.push_back(std::move(newAbility));
            break;  
        case 'F':
            newAbility = unique_ptr<Ability>(new Firewall(*this));
            abilities.push_back(std::move(newAbility));
            break;
        case 'P':
            newAbility = unique_ptr<Ability>(new Polarize(*this));
            abilities.push_back(std::move(newAbility));
            break;
        case 'X': // Steal not implemented
            throw invalid_argument("Steal not implemented");
            newAbility = unique_ptr<Ability>(new Steal(*this));
            abilities.push_back(std::move(newAbility));
            break;
        case 'C': // Stun not implemented
            newAbility = unique_ptr<Ability>(new Stun(*this));
            abilities.push_back(std::move(newAbility));
            break;
        case 'W': 
            newAbility = unique_ptr<Ability>(new Weaken(*this));
            abilities.push_back(std::move(newAbility));
            break;
        case 'M':
            newAbility = unique_ptr<Ability>(new Murder(*this));
            abilities.push_back(std::move(newAbility));
            break;
        default:
            return false;
    }
    return true;
}

void Player::reduceStunned() {
    for (auto& link : links) {
        link->reduceStunned();
    }
}
