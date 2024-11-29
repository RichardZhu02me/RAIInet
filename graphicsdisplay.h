#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

#include "observer.h"
#include "window.h"
#include "game.h"
#include <iostream>

class GraphicsDisplay : public Observer {
    Xwindow xw;
    Game& g;
    static const int HEADBAR = 10;
    static const int STRINGHEIGHT = 12;
    static const int SIDE = 1;

 public:
    GraphicsDisplay(Game& g);
    void notify() override;
    ~GraphicsDisplay() override;
};

#endif
