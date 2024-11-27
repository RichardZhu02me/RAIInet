#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "observer.h"
#include "game.h"
#include <iostream>

class TextDisplay : public Observer {
    unique_ptr<Game> g;

 public:
    TextDisplay(unique_ptr<Game>& g)
    void notify() override;
    ~TextDisplay() override;
};

#endif
