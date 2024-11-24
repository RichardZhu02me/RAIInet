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

void Player::setLinks(string order){
    links.clear();
    if(order.size() > 16){
        throw "INVALID: Too many links";
    }
    char a = (playerNumber == 1)?'a':'A';
    unsigned int j = 0;
    for (unsigned int i = 0; i<order.size(); i=i+2) {
        links.push_back(make_shared<Link>((char)(a + j),(order[i] == 'V') ? 1 : 0,order[i+1]-'0'));
        ++j;
    }

    // set up row and col numbers and ownedBy for each link
    for (int i = 0; i < 8; ++i ) {
        links[i]->setCol(i);
        if ((i != 3) && (i != 4)) {
            if (playerNumber == 1) links[i]->setRow(0);
            else links[i]->setRow(7);
        }
        else {
            if (playerNumber == 1) links[i]->setRow(1);
            else links[i]->setRow(6);
        }
        links[i]->setOwnedBy(playerNumber);
    }
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
