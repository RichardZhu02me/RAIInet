#include <vector>
#include <iostream>
#include "grid.h"
#include "player.h"

using namespace std;

void playerSetup(Player* pl) {
    while (pl->getNumOfAbLeft() != 5) {
        string ability;

        cout << pl->name << ": You have " << pl->getNumOfAbLeft() << " abilities set!" << endl
            << "Please input the next ability you would like you set!" << endl;
        cin >> ability;
        if (ability == "download") {
            if (pl->getNumDownload() < 2) {
                pl->setAbility(ability);
            } else {
                cout << "You already have 2 " << ability << "s" << endl;
            }
        } else if (ability == "firewall") {
            if (pl->getNumFirewall() < 2) {
                pl->setAbility(ability);
            } else {
                cout << "You already have 2 " << ability << "s" << endl;
            }
        } else if (ability == "linkboost") {
            if (pl->getNumLinkboost() < 2) {
                pl->setAbility(ability);
            } else {
                cout << "You already have 2 " << ability << "s" << endl;
            }
        } else if (ability == "polarize") {
            if (pl->getNumPolarize() < 2) {
                pl->setAbility(ability);
            } else {
                cout << "You already have 2 " << ability << "s" << endl;
            }
        } else if (ability == "scan") {
            if (pl->getNumScan() < 2) {
                pl->setAbility(ability);
            } else {
                cout << "You already have 2 " << ability << "s" << endl;
            }
        }
    }   
}

int main() {
    Grid grid;
    unique_ptr<Player> p1 {new Player{1, "P1"}};
    unique_ptr<Player> p2 {new Player{2, "P2"}};

    PlayerSetup(p1);
    PlayerSetup(p2);
    
    return 0;
}
