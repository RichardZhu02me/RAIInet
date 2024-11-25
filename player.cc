 #include "player.h"
 #include <iostream>
 using namespace std;

Player::Player(string abilityOrder, string linkOrder, int number) :
playerNumber{number} {
    setAbilities(abilityOrder);
    setLinks(linkOrder);
}

Player::~Player(){
 //dont know what to put in here yet
}

void Player::setAbilities(string order){
    abilities.clear();
    if(order.size() > 5){
        throw "You cannot have more than 5 abilities";
    }
    for (unsigned int i = 0; i<order.size(); ++i) {
        abilities.push_back(make_shared<Ability>(order[i],i+1));
    }
}
