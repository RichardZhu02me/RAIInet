#ifndef GAME_H
#define GAME_H

#include <vector>
#include <map>
#include "cell.h"
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
    static const map<string, int> ABILITIES;
    Game();
    ~Game() override;

    Link& getLink(char l) const;
    //get the cell at the given row and column
    const Cell& getCell(size_t row, size_t col) const;
    Cell& getCell(size_t row, size_t col);

    char getState(size_t row, size_t col) const override;

    //runs the given command
    void runCommand(string command);
    //runs the game
    void runGame();
    bool castAbility(int index, Cell& target);
    //move the link to the target cell
    bool moveLink(size_t x, size_t y, Link* linkRef, char direction);
    //helper function for moveLink
    bool moveLinkHelper(int y, int x, Link* linkRef);
    void removeLink(Cell& target);

    //ends the turn and gives control to the next player
    void endTurn();
    //get the player at the given player number
    Player& getPlayer(int playerNum) const;
    //declare the player at the given player number as the winner
    void win(int playerNum);
    //declare the player at the given player number as the loser
    void loss(int playerNum);
    //displays the abilities of the player at the given player number
    void displayAbilities(int playerNum);
    //checks if the game is over
    void checkWin();

    //get the player whose turn it is
    int getPlayerTurn();

private:
    vector<unique_ptr<Player>> players;
    void downloadLink(int playerNum, Link& link);
    vector<vector<unique_ptr<Cell>>> theBoard;
    bool playerCastedAbility;
    bool playerMovedLink;
    bool gameOver;
    int playerTurn;
    string fileName;
    bool useSequence = false;
    bool useSequenceFirst = false;
};

#endif
