#ifndef GRID_H
#define GRID_H

#include <vector>
#include "link.h"
using namespace std;

class Grid {
public:
    struct Cell {
        Link* link;
    };
    Grid();

    Cell& getCell(size_t index);
    const Cell& getCell(size_t index) const;
private:
   vector<vector<Cell>> theBoard;
};

#endif