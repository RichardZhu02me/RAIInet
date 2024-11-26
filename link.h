// Link.h
#ifndef LINK_H
#define LINK_H

#include <string>
#include "player.h"

class Link {
    std::string type; // "data" or "virus"
    int travelDistance;
    int strength;
    bool revealed;
    char symbol;
    Player* owner;
    size_t row;
    size_t col;

public:
    Link(const std::string& type, int strength, char symbol, Player* owner);
    ~Link();
    bool fightWon(const Link& opponent) const;
    void changeType();
    bool isRevealed() const;
    void reveal();
    const std::string& getType() const;
    int getStrength() const;
    int getTravelDistance() const;
    char getSymbol() const;
    Player* getOwner() const;
    bool boost();

    size_t getX() const;
    size_t getY() const;

    void setCoord(size_t y, size_t x);
    void weaken(int amount);
};

#endif // LINK_H
