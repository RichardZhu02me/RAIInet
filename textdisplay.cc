#include "textdisplay.h"
#include <iostream>

using namespace std;

TextDisplay::TextDisplay(unique_ptr<Game>& g)
    : g{g} {}

void TextDisplay::notify() {
    cout << "Player 1: " << endl;

    cout << "Downloaded: " << g->p1->getNumDownloaded();
}

  TextDisplay::~TextDisplay() {}