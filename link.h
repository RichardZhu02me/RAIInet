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
    Player* owner;

public:
    Link(const std::string& type, int strength, Player* owner);
    ~Link();
    bool fightWon(const Link& opponent) const;
    void changeType();
    bool isRevealed() const;
    void reveal();
    const std::string& getType() const;
    int getStrength() const;
    int getTravelDistance() const;
    Player* getOwner() const;
    bool boost();

    void weaken(int amount);
};

#endif // LINK_H
