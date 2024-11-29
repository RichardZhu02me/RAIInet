// Link.cc
#include "link.h"

Link::Link(const std::string& type, int strength, char symbol, int ownerId) :
    type(type), travelDistance(1), strength(strength), revealed(false), symbol(symbol), ownerId(ownerId), active(true) {}

Link::~Link(){}

bool Link::fightWon(Link& opponent) {
    opponent.reveal();
    this->reveal();
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

bool Link::getActive() const {
    return active;
}

void Link::deactivate() {
    active = false;
}

int Link::getStrength() const {
    return strength;
}

char Link::getSymbol() const {
    return symbol;
}

int Link::getOwnerId() const {
    return ownerId;
}

bool Link::boost() {
    travelDistance++;
    return true;
}

int Link::getTravelDistance() const {
    return travelDistance;
}

size_t Link::getX() const {
    return col;
}

size_t Link::getY() const {
    return row;
}

void Link::setCoord(size_t y, size_t x) {
    row = y;
    col = x;
}

void Link::weaken(int amount) {
    strength -= strength - amount < 0 ? 0 : strength - amount;
}
