#ifndef DOWNLOAD_H
#define DOWNLOAD_H     

#include "../ability.h"

using namespace std;


class Download: public Ability {
    bool Effect(Cell& target, bool debug=false) override;
public:
    Download(Player& caster);
    ~Download() override = default;
};

#endif