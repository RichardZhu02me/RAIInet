// Link.h
#ifndef LINK_H
#define LINK_H

#include <string>

class Link {
    std::string type; // "data" or "virus"
    int strength;
    bool revealed;

public:
    Link(const std::string& type, int strength);
    ~Link();
    bool fightWon(const Link& opponent) const;
    void changeType();
    bool isRevealed() const;
    void reveal();
    const std::string& getType() const;
    int getStrength() const;
};

#endif // LINK_H
