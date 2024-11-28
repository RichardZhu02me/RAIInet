#include "textdisplay.h"
#include <iostream>
#include "game.h"
#include "player.h"

using namespace std;

TextDisplay::TextDisplay(Game& g): g{g} {}

void TextDisplay::notify() {
    std:cout << "Player 1:" << endl;

    cout << "Downloaded: " << g.getPlayer(1)->getNumOfDataDld() << "D, "
        << g.getPlayer(1)->getNumOfVirusDld() << "V" << endl;

    cout << "Abilities: " << g.getPlayer(1)->getNumOfAbLeft() << endl;

    char base = 'a';
    for (size_t i = 0; i < 8; i++) {
        cout << (base + 0) << ": " << g.getPlayer(1)->getPlLink(i).getType()
            << g.getPlayer(1)->getPlLink(i).getStrength() << " ";
        if (i == 3 || i == 7) cout << endl;
    }

    cout << "========";

    for (size_t row = 0; row < 8; row++) {
        for (size_t col = 0; col < 8; col++) {
            cout << g.getState(row, col);
        }
        cout << endl;
    }

    cout << "========";

    cout << "Player 2:" << endl;

    cout << "Downloaded: " << g.getPlayer(2)->getNumOfDataDld() << "D, "
        << g.getPlayer(2)->getNumOfVirusDld() << "V" << endl;

    cout << "Abilities: " << g.getPlayer(2)->getNumOfAbLeft() << endl;

    base = 'A';
    for (size_t i = 0; i < 8; i++) {
        if (!(g.getPlayer(2)->getPlLink(i).isRevealed())) {
            cout << (base + 0) << ": ?  ";
        } else {
            cout << (base + 0) << ": " << g.getPlayer(2)->getPlLink(i).getType()
                << g.getPlayer(2)->getPlLink(i).getStrength() << " ";
        }
        if (i == 3 || i == 7) cout << endl;
    }
}

  TextDisplay::~TextDisplay() {}
