#include <vector>
#include <iostream>
#include "grid.h"
#include "player.h"

using namespace std;

void PlayerSetup(unique_ptr<Player>& pl, char c) {

    while (pl->getNumOfAbLeft() != 5) { //selects and sets up abilites of the player
        string ability;

        cout << "P" << pl->getPlayerNum() << ": You have " << pl->getNumOfAbLeft() << " abilities set!" << endl
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

    char currLink = c;
    int type;
    int strength;
    for (int i = 0; i < 8; i++) {
        bool found = false;
        for (auto link : pl->links) {
            if (link->getType() == type && link->getStrength() == strength) {
                found = true;
                break;
            }
        }
        if(!found) {
            pl->setLink(currLink, type, strength, pl);
            c++;
        } else {
            cout << "Invalid input, please try again!" << endl;
            i--;
        }
    }
}

void GridSetup(unique_ptr<Grid>& g, unique_ptr<Player>& p1, unique_ptr<Player>& p2) {
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            setCell(i, j, p1->links[j]);
        }
    }
    //setup cell and link connections
}

int main() {
    unique_ptr<Grid> grid{new Grid};
    unique_ptr<Player> p1 {new Player{1, "P1"}};
    unique_ptr<Player> p2 {new Player{2, "P2"}};

    PlayerSetup(p1, 'a');
    PlayerSetup(p2, 'b');
    GridSetup(grid, p1, p2);
    p1->makeAllVisible();

    //command interpreter for move ability etc
    
    return 0;
}
