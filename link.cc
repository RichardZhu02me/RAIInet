// Link.cc
#include "link.h"

Link::Link(const std::string& type, int strength, Player* owner) : type(type), strength(strength), revealed(false), owner(owner), travelDistance(1) {}

Link::~Link(){}

bool Link::fightWon(const Link& opponent) const {
    return (strength > opponent.strength) || (strength == opponent.strength && type == "data");
}

void Link::changeType() {
    type = (type == "data") ? "virus" : "data";
}

bool Link::isRevealed() const {
    return revealed;
}

void Link::reveal() {
    revealed = true;
}

const std::string& Link::getType() const {
    return type;
}

int Link::getStrength() const {
    return strength;
}

Player* Link::getOwner() const {
    return owner;
}

bool Link::boost() {
    travelDistance++;
    return true;
}

int Link::getTravelDistance() const {
    return travelDistance;
}

