#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "game.h"
#include <map>
#include <typeinfo> 
#include "./abilities/linkboost.h"
#include "./abilities/firewall.h"
#include "./abilities/download.h"
#include "./abilities/polarize.h"
#include "./abilities/scan.h"
#include "link.h"
#include "subject.h"
#include "cell.h"
#include "build.h"
#include <memory>

using namespace std;

const int Game::BOARD_SIZE = 8;
const int Game::MAX_PLAYERS = 2;
const int Game::MAX_LINK_DISTANCE = 2;
const map<string,int> Game::ABILITIES = {
    {"linkboost", 1},
    {"firewall", 2},
    {"download", 3},
    {"polarity", 4},
    {"scan", 5}
};

Game::Game() {
    theBoard.resize(BOARD_SIZE);
    for (auto& row : theBoard) {
        row.resize(BOARD_SIZE);
        for (auto& cell : row) {
            cell = make_unique<Cell>();
        }
    }
    
    gameOver = false;
    playerTurn = 0;
    playerCastedAbility = false;
    playerMovedLink = false;
}

Game::~Game() {}

Link& Game::getLink(char l) const {
    if ( l > 'a' && l < 'g') {
        return getPlayer(1).getPlLink(l -'a');
    } 
    else if ( l > 'A' && l < 'G') {
        return getPlayer(2).getPlLink(l - 'A'); 
    }
    throw invalid_argument("Invalid link character");
}  

const Cell& Game::getCell(size_t row, size_t col) const {
    return *theBoard[row][col];
}

Cell& Game::getCell(size_t row, size_t col) {
    return *theBoard[row][col];
}

char Game::getState(size_t row, size_t col) const {
    if (theBoard[row][col]->link != nullptr) {
        return theBoard[row][col]->link->getSymbol();
    } else if (theBoard[row][col]->firewall) {
        if (theBoard[row][col]->build->getPlayerId() == 1) {
            return 'm';
        } else {
            return 'w';
        }
    } else if (theBoard[row][col]->server) {
        return 'S';
    } else {
        return ' ';
    }
}

bool Game::castAbility(string ability, Cell& target) {
    //check if current player has the ability
    Ability& a = getPlayer(playerTurn).getAbility(Game::ABILITIES.at(ability));
    if(a.getAvailable()) {
        if (a.cast(target)) {
            getPlayer(playerTurn).removeAbility(Game::ABILITIES.at(ability));
            return true;
        }
    }
    return false;
}

void Game::downloadLink(int playerNum, string type) {
    if (type == "data") {
        getPlayer(playerNum).download(true);
    } else {
        getPlayer(playerNum).download(false);
    }
}

bool Game::moveLink(size_t x, size_t y, Link* linkRef, char direction) {
    int travelDistance = linkRef->getTravelDistance();
    int otherPlayerNum;
    if (playerTurn == 1) otherPlayerNum = 2;
    else otherPlayerNum = 1;

    switch(direction) {
        case 'u':
            if(y-travelDistance >= 0) {
                if (theBoard[y-travelDistance][x]->firewall == true) {
                    if (theBoard[y-travelDistance][x]->build->getPlayerId() != playerTurn) {
                        theBoard[y-travelDistance][x]->link->reveal();
                        if (theBoard[y-travelDistance][x]->link->getType() == "virus") {
                            getPlayer(playerTurn).download(false);
                            removeLink(*theBoard[y][x]);
                            linkRef->setCoord(100, 100);
                            return true;
                        }
                    }
                }

                if(theBoard[y-travelDistance][x]->link == nullptr) {
                    if (y-travelDistance == 0 && (x == 4 && x == 5) && playerTurn == 2) {
                        downloadLink(1, linkRef->getType());
                        removeLink(*theBoard[y][x]);
                        linkRef->setCoord(100, 100);
                        return true;
                    } else {
                        removeLink(*theBoard[y][x]);
                        theBoard[y-travelDistance][x]->link = linkRef;
                        linkRef->setCoord(x, y-1);
                        return true;
                    }
                } else {
                    if (linkRef->fightWon(*theBoard[y-travelDistance][x]->link)) {
                        removeLink(*theBoard[y][x]);
                        theBoard[y-travelDistance][x]->link->setCoord(100, 100);
                        theBoard[y-travelDistance][x]->link = linkRef;
                        linkRef->setCoord(x, y-1);
                        downloadLink(playerTurn, linkRef->getType());
                        return true;
                    } else {
                        removeLink(*theBoard[y][x]);
                        linkRef->setCoord(100, 100);
                        downloadLink(otherPlayerNum, theBoard[y-travelDistance][x]->link->getType());
                        return true;
                    }
                }
            } else if (playerTurn == 2) {
                downloadLink(2, linkRef->getType());
                removeLink(*theBoard[y][x]);
                linkRef->setCoord(100, 100);
                return true;
            } else {
                cout << "INVALID MOVEMENT!" << endl;
            }
            break;
            
        case 'd':
            if(y+travelDistance <= 7) {
                if (theBoard[y+travelDistance][x]->firewall == true) {
                    if (theBoard[y+travelDistance][x]->build->getPlayerId() != playerTurn) {
                        theBoard[y+travelDistance][x]->link->reveal();
                        if (theBoard[y+travelDistance][x]->link->getType() == "virus") {
                            getPlayer(playerTurn).download(false);
                            removeLink(*theBoard[y][x]);
                            linkRef->setCoord(100, 100);
                            return true;
                        }
                    }
                }

                if(theBoard[y+travelDistance][x]->link == nullptr) {
                    if (y+travelDistance == 7 && (x == 4 && x == 5) && playerTurn == 1) {
                        downloadLink(2, linkRef->getType());
                        removeLink(*theBoard[y][x]);
                        linkRef->setCoord(100, 100);
                        return true;
                    } else {
                        removeLink(*theBoard[y][x]);
                        theBoard[y+travelDistance][x]->link = linkRef;
                        linkRef->setCoord(x, y+1);
                        return true;
                    }
                } else {
                    if (linkRef->fightWon(*theBoard[y+travelDistance][x]->link)) {
                        removeLink(*theBoard[y][x]);
                        theBoard[y+travelDistance][x]->link->setCoord(100, 100);
                        theBoard[y+travelDistance][x]->link = linkRef;
                        linkRef->setCoord(x, y+1);
                        downloadLink(playerTurn, linkRef->getType());
                        return true;
                    } else {
                        removeLink(*theBoard[y][x]);
                        linkRef->setCoord(100, 100);
                        downloadLink(otherPlayerNum, theBoard[y+travelDistance][x]->link->getType());
                        return true;
                    }
                }
            } else if (playerTurn == 1) {
                downloadLink(1, linkRef->getType());
                removeLink(*theBoard[y][x]);
                linkRef->setCoord(100, 100);
                return true;
            } else {
                cout << "INVALID MOVEMENT!" << endl;
            }
            break;

        case 'l':
            if(x-travelDistance >= 0) {
                if (theBoard[y][x-travelDistance]->firewall == true) {
                    if (theBoard[y][x-travelDistance]->build->getPlayerId() != playerTurn) {
                        theBoard[y][x-travelDistance]->link->reveal();
                        if (theBoard[y][x-travelDistance]->link->getType() == "virus") {
                            getPlayer(playerTurn).download(false);
                            removeLink(*theBoard[y][x]);
                            linkRef->setCoord(100, 100);
                            return true;
                        }
                    }
                }

                if(theBoard[y][x-travelDistance]->link == nullptr) {
                    if (y == 7 && (x-travelDistance == 4 && x-travelDistance == 5) && playerTurn == 1) {
                        downloadLink(2, linkRef->getType());
                        removeLink(*theBoard[y][x]);
                        linkRef->setCoord(100, 100);
                        return true;
                    } else if (y == 0 && (x-travelDistance == 4 && x-travelDistance == 5) && playerTurn == 2) {
                        downloadLink(1, linkRef->getType());
                        removeLink(*theBoard[y][x]);
                        linkRef->setCoord(100, 100);
                        return true;
                    } else {
                        removeLink(*    theBoard[y][x]);
                        theBoard[y][x-travelDistance]->link = linkRef;
                        linkRef->setCoord(x-1, y);
                        return true;
                    }
                } else {
                    if (linkRef->fightWon(*theBoard[y][x-travelDistance]->link)) {
                        removeLink(*theBoard[y][x]);
                        theBoard[y][x-travelDistance]->link->setCoord(100, 100);
                        theBoard[y][x-travelDistance]->link = linkRef;
                        linkRef->setCoord(x-1, y);
                        downloadLink(playerTurn, linkRef->getType());
                        return true;
                    } else {
                        removeLink(*theBoard[y][x]);
                        linkRef->setCoord(100, 100);
                        downloadLink(otherPlayerNum, theBoard[y][x-travelDistance]->link->getType());
                        return true;
                    }
                }
            } else {
                cout << "INVALID MOVEMENT!" << endl;
            }
            break;
        case 'r':
            if(x+travelDistance <= 7) {
                if (theBoard[y][x+travelDistance]->firewall == true) {
                    if (theBoard[y][x+travelDistance]->build->getPlayerId() != playerTurn) {
                        theBoard[y][x+travelDistance]->link->reveal();
                        if (theBoard[y][x+travelDistance]->link->getType() == "virus") {
                            getPlayer(playerTurn).download(false);
                            removeLink(*theBoard[y][x]);
                            linkRef->setCoord(100, 100);
                            return true;
                        }
                    }
                }

                if(theBoard[y][x+travelDistance]->link == nullptr) {
                    if (y == 7 && (x+travelDistance == 4 && x+travelDistance == 5) && playerTurn == 1) {
                        downloadLink(2, linkRef->getType());
                        removeLink(*theBoard[y][x]);
                        linkRef->setCoord(100, 100);
                        return true;
                    } else if (y == 0 && (x+travelDistance == 4 && x+travelDistance == 5) && playerTurn == 2) {
                        downloadLink(1, linkRef->getType());
                        removeLink(*theBoard[y][x]);
                        linkRef->setCoord(100, 100);
                        return true;
                    } else {
                        removeLink(*theBoard[y][x]);
                        theBoard[y][x+travelDistance]->link = linkRef;
                        linkRef->setCoord(x+1, y);
                        return true;
                    }
                } else {
                    if (linkRef->fightWon(*theBoard[y][x+travelDistance]->link)) {
                        removeLink(*theBoard[y][x]);
                        theBoard[y][x+travelDistance]->link->setCoord(100, 100);
                        theBoard[y][x+travelDistance]->link = linkRef;
                        linkRef->setCoord(x-1, y);
                        downloadLink(playerTurn, linkRef->getType());
                        return true;
                    } else {
                        removeLink(*theBoard[y][x]);
                        linkRef->setCoord(100, 100);
                        downloadLink(otherPlayerNum, theBoard[y][x+travelDistance]->link->getType());
                        return true;
                    }
                }
            } else {
                cout << "INVALID MOVEMENT!" << endl;
            }
            break;
        default:
            return false;
    } //add firewall check, still haven't
    return false;
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

void Game::loss(int playerNum) { //don't need this
    cout << "Player " << (playerNum%(players.size()-1))+1 << " wins!" << endl;
    gameOver = true;
}

void Game::displayAbilities(int playerNum) {
    for (int i = 0; i < 8; i++) {
        Ability& a = getPlayer(playerNum).getAbility(i);
        cout << a.getId() << ": "
            << Ability::abilityLibrary.at(a.getId()) << "  ";

        if (a.getAvailable()) {
            cout << "AVAILABLE!";
        } else {
            cout << "UNAVAILABLE!";
        }
        
        cout << endl;
    }
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
    } else if(action == "ability" && !playerCastedAbility) {
        int abilityNum;
        ss >> abilityNum;
        string abilityName = Ability::abilityLibrary.at(abilityNum);
        size_t x, y;
        if (abilityName == "linkboost" || abilityName == "download" ||
                abilityName == "polarize" || abilityName == "scan") {
            string link;
            char linkChar;
            ss >> link;
            linkChar = link[0];
            Link linkRef = getLink(linkChar);
            x = linkRef.getX();
            y = linkRef.getY();
        } else if (abilityName == "firewall") {
            ss >> x >> y;
        }
        if (castAbility(abilityName, getCell(x, y))) {
            playerCastedAbility = true;
        }
    } else if(action == "abilities") {
        displayAbilities(playerTurn);
    } else if(action == "board") {
        notifyObservers();
    } else if (action == "sequence") {
        ss >> fileName;
        useSequence = true; //please don't put sequence in sequence, have not accounted for this
        useSequenceFirst = true;
    } else if (action == "quit") {
        playerMovedLink = true;
        gameOver = true;
    }
}

void Game::checkWin() {
    int otherPlayerNum;
    if (playerTurn == 1) otherPlayerNum = 2;
    else otherPlayerNum = 1;

    if (getPlayer(playerTurn).getNumOfDataDld() == 4 ||
            getPlayer(otherPlayerNum).getNumOfVirusDld() == 4) {
        win(playerTurn);
        playerMovedLink = true;
    } else if (getPlayer(otherPlayerNum).getNumOfDataDld() == 4 ||
                getPlayer(playerTurn).getNumOfVirusDld() == 4) {
        win(otherPlayerNum);
        playerMovedLink = true;
    }
}

void Game::runGame() {
    while (!gameOver) {
        string command;
        ifstream input;
        if (useSequenceFirst) {
            ifstream input(fileName);
            getline(input, command);
            useSequenceFirst = false;
            if (input.eof()) {
                useSequence = false;
            }
        } else if (useSequence) {
            getline(input, command);
            if (input.eof()) {
                useSequence = false;
            }
        }
        while(!playerMovedLink) {
            if (!useSequence) {
                getline(cin, command);
                runCommand(command);
                checkWin();
            } else {
                runCommand(command);
                checkWin();
            }
        }

        playerMovedLink = false;
        if (playerTurn == 1) playerTurn = 2;
        else if (playerTurn == 2) playerTurn = 1;
    }

}

Player& Game::getPlayer(int playerNum) const {
    return *players[playerNum-1];
}