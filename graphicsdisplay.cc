#include "graphicsdisplay.h"
#include <string>

using namespace std;

GraphicsDisplay::GraphicsDisplay(Game& g): g{g} {}

void GraphicsDisplay::notify() {
    xw.fillRectangle(0, 0, 500, 500, Xwindow::White);
    string currString;
    xw.drawString(SIDE, HEADBAR, "Player 1:");

    currString = "Downloaded: " + to_string(g.getPlayer(0).getNumOfDataDld()) + "D, "
        + to_string(g.getPlayer(0).getNumOfVirusDld()) + "V";
    xw.drawString(SIDE, HEADBAR + STRINGHEIGHT, currString);

    currString = "Abilities: " + to_string(g.getPlayer(0).getNumOfAbLeft());
    xw.drawString(SIDE, HEADBAR + 2*STRINGHEIGHT, currString);

    char base = 'a';
    currString = "";
    for (int i = 0; i < 8; i++) {
        char currBase = base + i;
        char currChar = static_cast<char>(currBase);
        char charType = g.getPlayer(0).getPlLink(i).getType() == "data" ? 'D' : 'V';
        currString = currString + currChar + ": " + charType + to_string(g.getPlayer(0).getPlLink(i).getStrength()) + " ";
        if (i == 3) {
            xw.drawString(SIDE, HEADBAR + 3*STRINGHEIGHT, currString);
            currString = "";
        } else if (i == 7) {
            xw.drawString(SIDE, HEADBAR + 4*STRINGHEIGHT, currString);
            currString = "";
        }
    }

    currString = "========";
    xw.drawString(SIDE, HEADBAR + 5*STRINGHEIGHT, currString);


    for (size_t row = 0; row < 8; row++) {
        currString = "";
        for (size_t col = 0; col < 8; col++) {
            currString = currString + g.getState(row, col);
        }
        xw.drawString(SIDE, HEADBAR + (6+row)*STRINGHEIGHT, currString);
    }

    currString = "========";
    xw.drawString(SIDE, HEADBAR + 14*STRINGHEIGHT, currString);

    xw.drawString(SIDE, HEADBAR + 15*STRINGHEIGHT, "Player 2:");

    currString = "Downloaded: " + to_string(g.getPlayer(1).getNumOfDataDld()) + "D, "
        + to_string(g.getPlayer(1).getNumOfVirusDld()) + "V";
    xw.drawString(SIDE, HEADBAR + 16*STRINGHEIGHT, currString);

    currString = "Abilities: " + to_string(g.getPlayer(1).getNumOfAbLeft());
    xw.drawString(SIDE, HEADBAR + 17*STRINGHEIGHT, currString);

    base = 'A';
    currString = "";
    for (int i = 0; i < 8; i++) {
        char currBase = base + i;
        char currChar = static_cast<char>(currBase);
        char charType = g.getPlayer(1).getPlLink(i).getType() == "data" ? 'D' : 'V';
        currString = currString + currChar + ": " + charType + to_string(g.getPlayer(1).getPlLink(i).getStrength()) + " ";
        if (i == 3) {
            xw.drawString(SIDE, HEADBAR + 18*STRINGHEIGHT, currString);
            currString = "";
        } else if (i == 7) {
            xw.drawString(SIDE, HEADBAR + 19*STRINGHEIGHT, currString);
            currString = "";
        }
    }

}

  GraphicsDisplay::~GraphicsDisplay() {}
