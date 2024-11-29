#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

#include "observer.h"
#include "window.h"
#include "game.h"
#include <iostream>

class GraphicsDisplay : public Observer {
    Xwindow xw;
    Game& g;

 public:
    GraphicsDisplay(Game& g);
    void notify() override;
    ~GraphicsDisplay() override;
};

#endif
