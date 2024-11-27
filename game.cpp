#include <iostream>
#include <sstream>
#include "game.h"

using namespace std;

const int Game::BOARD_SIZE = 8;
const int Game::MAX_PLAYERS = 2;
const int Game::MAX_LINK_DISTANCE = 2;
const vector<string> Game::ABILITIES = {"linkboost","firewall","download","polarity","scan"};

Game::Game() {
            theBoard = vector<vector<Cell>>(BOARD_SIZE, vector<Cell>(BOARD_SIZE));
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    theBoard[i][j].link = nullptr;
                }
             }
}

Link* Game::getLink(size_t row, size_t col) {
    return theBoard[row][col].link;
}  

Game::Cell& Game::getCell(size_t row, size_t col){
    return theBoard[row][col];
}

bool Game::castAbility(string ability, Cell& target) {
    //check if current player has the ability
    Ability* a = players[playerTurn]->getAbility(ability);
    if(a != nullptr) {
        return a->cast(*players[playerTurn], target);
    }
    return false;
}
bool Game::moveLink(int x, int y, char direction) {
    Link* linkRef = theBoard[x][y].link;
    int travelDistance = linkRef->getTravelDistance();
    switch(direction) {
        case 'u':
            if(theBoard[y-travelDistance][x].link == nullptr) {
                theBoard[y][x].link = 0;
                theBoard[y-travelDistance][x].link = linkRef;
                return true;
            }
            break;
        case 'd':
            if(theBoard[y+travelDistance][x].link == nullptr) {
                theBoard[y][x].link = 0;
                theBoard[y+travelDistance][x].link = linkRef;
                return true;
            }
            break;
        case 'l':
            if(theBoard[y][x-travelDistance].link == nullptr) {
                theBoard[y][x].link = 0;
                theBoard[y][x-travelDistance].link = linkRef;
            break;
            }
        case 'r':
            if(theBoard[y][x+travelDistance].link == nullptr) {
                theBoard[y][x].link = 0;
                theBoard[y][x+travelDistance].link = linkRef;
                return true;
            }
            break;
        default:
            return false;
    }
}

void Game::removeLink(Cell& target) {
    target.link = nullptr;
}

void Game::endTurn() {
    playerTurn++;
    playerTurn %= players.size();
    playerCastedAbility = false;
}

void Game::runCommand(string command) {
    stringstream ss(command);
    string action;
    ss >> action;
    if(action == "move") {
        char direction;
        ss >> direction;
        int x, y;
        ss >> x >> y;
        if (moveLink(x, y, direction)) {
            Game::endTurn();
        }
    }
    else if(action == "ability" && !playerCastedAbility) {
        string abilityName;
        ss >> abilityName;
        int x, y;
        ss >> x >> y;
        castAbility(abilityName, getCell(x, y));
    }
    else {
        cout << "Invalid command" << endl;
    }
}