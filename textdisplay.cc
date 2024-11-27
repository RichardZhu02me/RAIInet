#include "textdisplay.h"
#include <iostream>

using namespace std;

TextDisplay::TextDisplay(unique_ptr<Game> g)
    : g{g} {}

void TextDisplay::notify() {
    cout << "Player 1:" << endl;

    cout << "Downloaded: " << g->getp1()->getNumOfDataDld() << "D, "
        << g->getp1()->getNumofVirusDld() << "V" << endl;

    cout << "Abilities: " << g->getp1()->numOfAbLeft() << endl;

    char base = 'a';
    for (int i = 0; i < 8; i++) {
        cout << (base + 0) << ": " << g->getp1()->getLink(i)->getType()
            << g->getp1()->getLink(i)->getStrength() << " ";
        if (i == 3 || i == 7) cout << endl;
    }

    cout << "========";

    //output what's in cells, use getState of some sort, figure out tomorrow

    cout << "========";

    cout << "Player 2:" << endl;

    cout << "Downloaded: " << g->getp2()->getNumOfDataDld() << "D, "
        << g->getp2()->getNumofVirusDld() << "V" << endl;

    cout << "Abilities: " << g->getp2()->numOfAbLeft() << endl;

    base = 'A';
    for (int i = 0; i < 8; i++) {
        if (g->getp1()->getLink(i)->isHidden()) {
            cout << (base + 0) << ": ?  ";
        } else {
            cout << (base + 0) << ": " << g->getp1()->getLink(i)->getType()
                << g->getp1()->getLink(i)->getStrength() << " ";
        }
        if (i == 3 || i == 7) cout << endl;
    }
}

  TextDisplay::~TextDisplay() {}