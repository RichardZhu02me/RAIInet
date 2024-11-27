#ifndef GAME_H
#define GAME_H

#include <vector>
#include "link.h"
#include "player.h"
#include "ability.h"
using namespace std;

class Game {
public:
    static const int BOARD_SIZE;
    static const int MAX_PLAYERS;
    static const int MAX_LINK_DISTANCE;
    static const vector<string> ABILITIES;
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
    Game();

    Link* getLink(size_t row, size_t col);
    //get the cell at the given row and column
    Cell& getCell(size_t row, size_t col);

    void runCommand(string command);
    bool castAbility(string ability, Cell& target);
    bool moveLink(int x, int y, char direction);
    void removeLink(Cell& target);
    void endTurn();
    Player* getPlayer(int playerNum);
private:
   vector<vector<Cell>> theBoard;
   vector<unique_ptr<Player>> players;
   int playerTurn;
   bool playerCastedAbility;
   bool playerMovedLink;
};

#endif