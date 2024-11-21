#ifndef GRID_H
#define GRID_H

#include <vector>
#include "link.h"
#include "player.h"
using namespace std;

class Grid {
public:
    class Build {
        Player* player;
        string structureName;
    public:
        Player* getPlayer() const;
        string getStructureName() const;
        static Build* buildFirewall(Player& player);
        static Build* buildServer(Player& player);
    };
    struct Cell {
        Link* link;
        bool firewall;
        bool server;
        Build* build;
        
    };
    Grid();

    Link* getLink(size_t row, size_t col);
    //get the cell at the given row and column
    Cell& getCell(size_t row, size_t col);
private:
   vector<vector<Cell>> theBoard;
};

#endif