#ifndef GAME_H
#define GAME_H

#include <vector>
#include <map>
#include "link.h"
#include "player.h"
#include "ability.h"
#include "subject.h"
using namespace std;

class Game : public Subject{
public:
    static const int BOARD_SIZE;
    static const int MAX_PLAYERS;
    static const int MAX_LINK_DISTANCE;
    static const map<string, string> ABILITIES;
    class Build {
        int playerId;
        Player* player;
        string structureName;
    public:
        int getPlayerId() const;
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
    ~Game() override;

    Link& getLink(char l) const;
    //get the cell at the given row and column
    const Cell& getCell(size_t row, size_t col) const;
    Cell& getCell(size_t row, size_t col);

    char getState(size_t row, size_t col) const override;

    void runCommand(string command);
    void runGame();
    bool castAbility(string ability, Cell& target);
    bool moveLink(size_t x, size_t y, Link* linkRef, char direction);
    void removeLink(Cell& target);

    void endTurn();
    Player* getPlayer(int playerNum) const;
    void win(int playerNum);
    void loss(int playerNum);
    void displayAbilities(int playerNum);
    void checkWin();

private:
   void downloadLink(int playerNum, string type);
   vector<vector<Cell>> theBoard;
   vector<unique_ptr<Player>> players;
   int playerTurn;
   bool playerCastedAbility;
   bool playerMovedLink;
   bool gameOver;
   string fileName;
   bool useSequence = false;
   bool useSequenceFirst = false;
};

#endif