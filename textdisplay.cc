#include "textdisplay.h"
#include <iostream>
#include "game.h"
#include "player.h"

using namespace std;

TextDisplay::TextDisplay(unique_ptr<Game> g)
    : g{g} {}

void TextDisplay::notify() {
    cout << "Player 1:" << endl;

    cout << "Downloaded: " << g->getPlayer(1)->getNumOfDataDld() << "D, "
        << g->getPlayer(1)->getNumofVirusDld() << "V" << endl;

    cout << "Abilities: " << g->getPlayer(1)->getNumOfAbLeft() << endl;

    char base = 'a';
    for (int i = 0; i < 8; i++) {
        cout << (base + 0) << ": " << g->getPlayer(1)->getLink(i)->getType()
            << g->getPlayer(1)->getLink(i)->getStrength() << " ";
        if (i == 3 || i == 7) cout << endl;
    }

    cout << "========";

    //output what's in cells, use getState of some sort, figure out tomorrow

    cout << "========";

    cout << "Player 2:" << endl;

    cout << "Downloaded: " << g->getPlayer(2)->getNumOfDataDld() << "D, "
        << g->getPlayer(2)->getNumofVirusDld() << "V" << endl;

    cout << "Abilities: " << g->getPlayer(2)->getNumOfAbLeft() << endl;

    base = 'A';
    for (int i = 0; i < 8; i++) {
        if (g->getPlayer(2)->getLink(i)->isHidden()) {
            cout << (base + 0) << ": ?  ";
        } else {
            cout << (base + 0) << ": " << g->getPlayer(2)->getLink(i)->getType()
                << g->getPlayer(2)->getLink(i)->getStrength() << " ";
        }
        if (i == 3 || i == 7) cout << endl;
    }
}

  TextDisplay::~TextDisplay() {}
  