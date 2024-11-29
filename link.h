// Link.h
#ifndef LINK_H
#define LINK_H

#include <string>

using namespace std;
class Link {
    string type; // "data" or "virus"
    int travelDistance;
    int strength;
    bool revealed;
    bool active;
    char symbol;
    int ownerId;
    size_t row;
    size_t col;

public:
    Link(const string& type, int strength, char symbol, int ownerId);
    ~Link();
    bool fightWon(Link& opponent);
    void changeType();
    bool isRevealed() const;
    void reveal();
    const string& getType() const;
    int getStrength() const;
    int getTravelDistance() const;
    char getSymbol() const;
    int getOwnerId() const;
    bool boost();
    size_t getX() const;
    size_t getY() const;
    bool getActive() const;
    void deactivate();
    void setCoord(size_t y, size_t x);
    void weaken(int amount);
};

#endif // LINK_H
