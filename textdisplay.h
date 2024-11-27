#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "observer.h"
#include "game.h"
#include <iostream>

class TextDisplay : public Observer {
    Game* g;

 public:
    TextDisplay(Game* g);
    void notify() override;
    ~TextDisplay() override;
};

#endif
