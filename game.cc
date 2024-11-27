#include <iostream>
#include <sstream>
#include "game.h"
#include <map>
#include <typeinfo> 
#include "linkboost.h"
#include "firewall.h"
#include "download.h"
#include "polarize.h"
#include "scan.h"
#include "link.h"
#include "subject.h"

using namespace std;

const int Game::BOARD_SIZE = 8;
const int Game::MAX_PLAYERS = 2;
const int Game::MAX_LINK_DISTANCE = 2;
const map<string,string> Game::ABILITIES = {
    {"linkboost", typeid(LinkBoost).name()},
    {"firewall", typeid(Firewall).name()},
    {"download", typeid(Download).name()},
    {"polarity", typeid(Polarize).name()},
    {"scan", typeid(Scan).name()}
};

Game::Game() {
    theBoard = vector<vector<Cell>>(BOARD_SIZE, vector<Cell>(BOARD_SIZE));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            theBoard[i][j].link = nullptr;
        }
    }
    gameOver = false;
    playerTurn = 0;
    playerCastedAbility = false;
    playerMovedLink = false;
}

Link& Game::getLink(char l) const {
    if ( l > 'a' && l < 'g') {
        return getPlayer(1)->getPlLink(l -'a');
    } 
    else if ( l > 'A' && l < 'G') {
        return getPlayer(2)->getPlLink(l - 'A'); 
    }
    throw invalid_argument("Invalid link character");
}  

const Game::Cell& Game::getCell(size_t row, size_t col) const{
    return theBoard[row][col];
}

Game::Cell& Game::getCell(size_t row, size_t col) {
    return theBoard[row][col];
}

char Game::getState(size_t row, size_t col) const {
    if (getCell(row, col).firewall) {
        if (getCell(row, col).build->getPlayer()->getPlayerNum() == 1) {
            return 'm';
        } else {
            return 'w';
        }
    } else if (getCell(row, col).server) {
        return 'S';
    } else {
        if (getCell(row, col).link == nullptr) {
            return ' ';
        } else {
            return getCell(row,col).link->getSymbol();
        }
    }
}

bool Game::castAbility(string ability, Cell& target) {
    //check if current player has the ability
    Ability* a = players[playerTurn]->getAbility(Game::ABILITIES.at(ability));
    if(a != nullptr) {
        if (a->cast(*players[playerTurn], target)) {
            players[playerTurn]->removeAbility(a);
            return true;
        }
    }
    return false;
}

bool Game::moveLink(size_t x, size_t y, Link* linkRef, char direction) {
    int travelDistance = linkRef->getTravelDistance();
    switch(direction) {
        case 'u':
            if(theBoard[y-travelDistance][x].link == nullptr) {
                theBoard[y][x].link = 0;
                theBoard[y-travelDistance][x].link = linkRef;
                linkRef->setCoord(x, y+1);
                return true;
            }
            break;
        case 'd':
            if(theBoard[y+travelDistance][x].link == nullptr) {
                theBoard[y][x].link = 0;
                theBoard[y+travelDistance][x].link = linkRef;
                linkRef->setCoord(x, y-1);
                return true;
            }
            break;
        case 'l':
            if(theBoard[y][x-travelDistance].link == nullptr) {
                theBoard[y][x].link = 0;
                theBoard[y][x-travelDistance].link = linkRef;
                linkRef->setCoord(x-1, y);
                return true;
            }
            break;
        case 'r':
            if(theBoard[y][x+travelDistance].link == nullptr) {
                theBoard[y][x].link = 0;
                theBoard[y][x+travelDistance].link = linkRef;
                linkRef->setCoord(x+1, y);
                return true;
            }
            break;
        default:
            return false;
    } //still have to check for fights and downloads
}

void Game::removeLink(Cell& target) {
    target.link = nullptr;
}

void Game::endTurn() {
    playerTurn++;
    playerTurn %= players.size();
    playerCastedAbility = false;
    playerMovedLink = true;
}

void Game::win(int playerNum) {
    cout << "Player " << playerNum << " wins!" << endl;
    gameOver = true;
}

void Game::loss(int playerNum) {
    cout << "Player " << (playerNum%(players.size()-1))+1 << " wins!" << endl;
    gameOver = true;
}

void Game::runCommand(string command) {
    stringstream ss(command);
    string action;
    ss >> action;
    if(action == "move") {
        char direction;
        ss >> direction;
        char l;
        ss >> l;
        Link& linkRef = getLink(l);
        int x = linkRef.getX();
        int y = linkRef.getY();
        if (moveLink(x, y, &linkRef, direction)) {
            Game::endTurn();
        }
    }
    else if(action == "ability" && !playerCastedAbility) {
        string abilityName;
        ss >> abilityName;
        int x, y;
        ss >> x >> y;
        if (castAbility(abilityName, getCell(x, y))) {
            playerCastedAbility = true;
        }
    } else if(action == "abilities") {
        
    }
}

void Game::runGame() {
    while (!gameOver) {
        while(!playerMovedLink) {
            string command;
            getline(cin, command);
            runCommand(command);
        }
        playerMovedLink == false;
        notifyObservers();
    }
}
