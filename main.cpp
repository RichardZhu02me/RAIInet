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
    int row = 1;
    for (int col = 1; col <= 8; col++) {
        if (col != 4 && col != 5) {
            getCell(row, col)->link = p1->link[col];
        }
    }
    for (int col = 4; col <= 5; col++) {
        getCell(row, col)->build->buildServer(p1);
    }

    row = 2;
    for (int col = 4; col <= 5; col++) {
        getCell(row, col)->link = p1->link[col];
    }

    row = 7;
    for (int col = 4; col <= 5; col++) {
        getCell(row, col)->link = p2->link[col];
    }

    row = 8;
    for (int col = 1; col <= 8; col++) {
        if (col != 4 && col != 5) {
            getCell(row, col)->link = p2->link[col];
        }
    }
    for (int col = 4; col <= 5; col++) {
        getCell(row, col)->build->buildServer(p2);
    }
}

int main() {
    unique_ptr<Grid> grid{new Grid};
    unique_ptr<Player> p1 {new Player{1, "P1"}};
    unique_ptr<Player> p2 {new Player{2, "P2"}};

    PlayerSetup(p1, 'a');
    PlayerSetup(p2, 'b');
    GridSetup(grid, p1, p2);
    p1->makeAllVisible();
    
    bool p1won = false;
    bool p2won = false;
    bool p1turn = true;
    while (!p1won && !p2won) {
        //let players take turns performing actions, as long as game not over
        //prompt command input
        //if move, check if link exists, and move for them if so
        //if ability, check if ability exists, and use ability for them
    }

    return 0;
}
