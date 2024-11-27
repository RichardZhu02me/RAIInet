// Link.cc
#include "link.h"

Link::Link(const std::string& type, int strength) : type(type), strength(strength), revealed(false) {}

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
