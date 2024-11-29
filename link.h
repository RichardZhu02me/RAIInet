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
    int stunned;
public:
    //constructor for the link
    Link(const string& type, int strength, char symbol, int ownerId);
    //destructor for the link 
    ~Link();
    //determines if the link won the fight
    bool fightWon(Link& opponent);
    //changes the type of the link
    void changeType();
    //get whether the link is revealed
    bool isRevealed() const;
    //reveal the link
    void reveal();
    //get the type of the link
    const string& getType() const;
    //get the strength of the link
    int getStrength() const;
    //get the travel distance of the link
    int getTravelDistance() const;
    //get the symbol of the link
    char getSymbol() const;
    //get the owner id of the link
    int getOwnerId() const;
    //boost the link, increases move distance by 1
    bool boost();
    //get the x coordinate of the link
    size_t getX() const;
    //get the y coordinate of the link
    size_t getY() const;
    //get whether the link is active
    bool getActive() const;
    //deactivate the link
    void deactivate();
    //set the coordinates of the link
    void setCoord(size_t y, size_t x);
    //weaken the link, decreases strength by the given amount
    void weaken(int amount);
    //set the stunned duration of the link
    void setStunned(int turns);
    //reduce the stunned duration of the link by 1
    void reduceStunned();
    //get the stunned duration of the link
    int getStunDuration() const;
};

#endif // LINK_H
