#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include "game.h"
#include "player.h"

using namespace std;

//Player can set up their 5 abilities
void abilitySetup(unique_ptr<Game>& g, size_t playerNum, vector<string> abilities) {
    Player* pl = g->getPlayer(playerNum);
    for (int i = 0; i < 5; i++) {
        pl->addAbility(abilities[i]);
    }
}

//Player sets up where they want their links on the board before game starts
void linkSetup(unique_ptr<Game>& g, size_t playerNum, string linkFile) {
    Player* pl = g->getPlayer(playerNum);
    ifstream input(linkFile);
    string word;

    if (playerNum == 1) char base = 'a';
    else char base = 'A';

    for (int id = 0; id < 8; id++) {
        inputFile >> word;
        char type = word[0];
        int strength = word[1] - '0';
        pl->setLink(type, strength, (base + id));
    }
}

//This options allows the player to let the game randomly decide where the links go on the board
void linkSetupRandom(Game& g, size_t playerNum) {
    Player* pl = g->getPlayer(playerNum);
    // 4 Data links and 4 Virus links
    vector<string> linkVals = {"D1", "D2", "D3", "D4", "V1", "V2", "V3", "V4"};
    random_device rd;
    mt19937 gen(rd());

    shuffle(linkVals.begin(), linkVals.end(), gen);

    for (size_t id = 0; id < 8; id++) {
        char type = linkVals[id][0];
        int strength = linkVals[id][1] - '0';
        pl->setLink(type, strength, id);
    }
}

//Creates the grid board that the game will take place on
void gridSetup(unique_ptr<Game>& g) {
    Player* p1 = g->getPlayer(1);
    Player* p2 = g->getPlayer(2);

    size_t row = 1;
    for (size_t col = 1; col <= 8; col++) {
        if (col != 4 && col != 5) {
            g->getCell(row, col)->link = p1->link[col];
            p1->link[col]->setCoord(row, col);
        }
    }
    for (size_t col = 4; col <= 5; col++) {
        g->getCell(row, col)->build->buildServer(p1);
    }

    row = 2;
    for (size_t col = 4; col <= 5; col++) {
        g->getCell(row, col)->link = p1->link[col];
        p1->link[col]->setCoord(row, col);
    }

    row = 7;
    for (size_t col = 4; col <= 5; col++) {
        g->getCell(row, col)->link = p2->link[col];
        p2->link[col]->setCoord(row, col);
    }

    row = 8;
    for (size_t col = 1; col <= 8; col++) {
        if (col != 4 && col != 5) {
            g->getCell(row, col)->link = p2->link[col];
            p2->link[col]->setCoord(row, col);
        }
    }
    for (size_t col = 4; col <= 5; col++) {
        g->getCell(row, col)->build->buildServer(p2);
    }
}

int main(int argc, char* argv[]) {
    unique_ptr<Game> g{new Game};

    const string DEFAULTAB = "LFDSP";

    string abilities1;
    string abilities2;
    string linkFile1;
    string linkFile2;

    bool graphics = false;
    bool ab1setup = false;
    bool ab2setup = false;
    bool links1setup = false;
    bool links2setup = false;

    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "-ability1" && i + 1 < argc) {
            abilities1 = argv[++i];
            abilitySetup(g, 0, abilities1);
            ab1setup = true;
        } else if (arg == "-ability2" && i + 1 < argc) {
            abilities2 = argv[++i];
            abilitySetup(g, 1, abilities2);
            ab2setup = true;
        } else if (arg == "-link1" && i + 1 < argc) {
            linkFile1 = argv[++i];
            linkSetup(g, 0, linkFile1);
            links1setup = true;
        } else if (arg == "-link2" && i + 1 < argc) {
            linkFile2 = argv[++i];
            linkSetup(g, 1, linkFile2);
            links2setup = true;
        } else if (arg == "-graphics") {
            graphics = true;
        }
    }
    
    if (!ab1setup) {
        abilitySetup(g, 0, DEFAULTAB);
    }

    if (!ab2setup) {
        abilitySetup(g, 1, DEFAULTAB);
    }

    if (!links1Setup) {
        linkSetupRandom(g, 0);
    }

    if (!links1Setup) {
        linkSetupRandom(g, 1);
    }

    gridSetup(g);
    g->attach(&g)
    g->runGame();

    return 0;
}
