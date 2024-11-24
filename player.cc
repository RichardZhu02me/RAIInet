 #include "player.h"
 #include <iostream>
 using namespace std;

Player::Player(string abilityOrder, string linkOrder, int number) :
playerNumber{number} {
    setAbilities(abilityOrder);
    setLinks(linkOrder);
}

Player::~Player(){
    vector <Cell*> fwCells;
    for(unsigned int i=0; i< fwCells.size(); ++i){
        fwCells[i]->isFireWall = false;
        fwCells[i]->fireWallOwner = 0;
    }
    for (int i = 0; i < 2; ++i) {
        SSCells[i]->isServerPort = false;
        SSCells[i]->whoseServerPort = 0;
    }
}
