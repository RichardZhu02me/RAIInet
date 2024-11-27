#include <vector>
#include "game.h"
#include "player.h"

using namespace std;

void abilitySetup(unique_ptr<Game>& g, int playerNum, string abilities) {
    unique_ptr<Player> pl = g->players[playerNum];
    for (int i = 0; i < 5; i++) {
        pl->setAbility(abilities[i]);
    }
}

void linkSetup(unique_ptr<Game>& g, int playerNum, string linkFile) {
    unique_ptr<Player> pl = g->players[playerNum];
    ifstream input(linkFile);
    string word;
    for (int id = 0; id < 8; id++) {
        inputFile >> word;
        char type = word[0];
        int strength = word[1] - '0';
        pl->setLink(type, strength, id);
    }
}

void linkSetupRandom(unique_ptr<Game>& g, int playerNum) {
    unique_ptr<Player> pl = g->players[playerNum];
    vector<string> linkVals = {"D1", "D2", "D3", "D4", "V1", "V2", "V3", "V4"};
    random_device rd;
    mt19937 gen(rd());

    shuffle(linkVals.begin(), linkVals.end(), gen);

    for (int id = 0; id < 8; id++) {
        char type = linkVals[id][0];
        int strength = linkVals[id][1] - '0';
        pl->setLink(type, strength, id);
    }
}

void gridSetup(unique_ptr<Game>& g) {
    int row = 1;
    for (int col = 1; col <= 8; col++) {
        if (col != 4 && col != 5) {
            g->getCell(row, col)->link = g->p1->link[col];
        }
    }
    for (int col = 4; col <= 5; col++) {
        g->getCell(row, col)->build->buildServer(p1);
    }

    row = 2;
    for (int col = 4; col <= 5; col++) {
        g->getCell(row, col)->link = g->p1->link[col];
    }

    row = 7;
    for (int col = 4; col <= 5; col++) {
        g->getCell(row, col)->link = g->p2->link[col];
    }

    row = 8;
    for (int col = 1; col <= 8; col++) {
        if (col != 4 && col != 5) {
            g->getCell(row, col)->link = g->p2->link[col];
        }
    }
    for (int col = 4; col <= 5; col++) {
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
    g->runGame();

    return 0;
}
