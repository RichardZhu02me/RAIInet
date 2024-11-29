#include "textdisplay.h"
#include <iostream>
#include "game.h"
#include "player.h"

using namespace std;

TextDisplay::TextDisplay(Game& g): g{g} {}

void TextDisplay::notify() {
    cout << "Player 1:" << endl;

    cout << "Downloaded: " << g.getPlayer(0).getNumOfDataDld() << "D, "
        << g.getPlayer(0).getNumOfVirusDld() << "V" << endl;

    cout << "Abilities: " << g.getPlayer(0).getNumOfAbLeft() << endl;

    char base = 'a';
    for (int i = 0; i < 8; i++) {
        char currBase = base + i;
        char currChar = static_cast<char>(currBase);
        char charType = g.getPlayer(0).getPlLink(i).getType() == "data" ? 'D' : 'V';
        cout << currChar << ": " << charType << g.getPlayer(0).getPlLink(i).getStrength() << " ";
        if (i == 3 || i == 7) cout << endl;
    }

    cout << "========" << endl;

    for (size_t row = 0; row < 8; row++) {
        for (size_t col = 0; col < 8; col++) {
            cout << g.getState(row, col);
        }
        cout << endl;
    }

    cout << "========" << endl;

    cout << "Player 2:" << endl;

    cout << "Downloaded: " << g.getPlayer(1).getNumOfDataDld() << "D, "
        << g.getPlayer(1).getNumOfVirusDld() << "V" << endl;

    cout << "Abilities: " << g.getPlayer(1).getNumOfAbLeft() << endl;

    base = 'A';
    for (int i = 0; i < 8; i++) {
        if (!(g.getPlayer(1).getPlLink(i).isRevealed())) {
            int currBase = base + i;
            char currChar = static_cast<char>(currBase);
            cout << currChar << ": ?  ";
        } else {
            int currBase = base + i;
            char currChar = static_cast<char>(currBase);
            char charType = g.getPlayer(1).getPlLink(i).getType() == "data" ? 'D' : 'V';
            cout << currChar << ": " << charType << g.getPlayer(1).getPlLink(i).getStrength() << " ";
        }
        if (i == 3 || i == 7) cout << endl;
    }
}

  TextDisplay::~TextDisplay() {}
