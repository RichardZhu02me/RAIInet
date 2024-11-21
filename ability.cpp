#include "ability.h"

using namespace std;

//cast the ability on the target cell
//return true if the ability was cast successfully
//return false otherwise
bool Ability::cast(Grid::Cell* target) {
    if(Effect(target)) return true;
    return false;
}
