 #include "player.h"
 #include <iostream>
 using namespace std;

Player::Player(int number) : playerNum{number} {}

Player::~Player(){}

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
