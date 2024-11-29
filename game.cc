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

    players.emplace_back(unique_ptr<Player> {new Player(0)});
    players.emplace_back(unique_ptr<Player> {new Player(1)});
    cout << "MAKING GAME" << endl;
 
    gameOver = false;
    playerTurn = 0;
    playerCastedAbility = false;
    playerMovedLink = false;
}

Game::~Game() {}

Link& Game::getLink(char l) const {
    if ( l >= 'a' && l <= 'h') {
        return getPlayer(0).getPlLink(l -'a');
    } 
    else if ( l >= 'A' && l <= 'H') {
        return getPlayer(1).getPlLink(l - 'A'); 
    }
    throw invalid_argument("Invalid link character " +l);
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
        return '.';
    }
}

//casts the Ability at index 1
//takes a 
bool Game::castAbility(int index, Cell& target) {
    //check if current player has the ability
    Ability& a = getPlayer(playerTurn).getAbility(index);
    if(a.getAvailable()) {
        if (a.cast(target)) {
            return true;
        }
    }
    return false;
}


void Game::downloadLink(int playerNum, Link& link) {
    if (link.getType() == "data") {
        getPlayer(playerNum).download(true);
    } else {
        getPlayer(playerNum).download(false);
    }
    link.deactivate();
}

//helper function for moveLink
//handles everything, requires a direction
bool Game::moveLinkHelper(int targetY, int targetX, Link* linkRef) {
    Cell& currentCell = getCell(linkRef->getY(), linkRef->getX());
    // border check at the beginning of the function
    //player 0 wants to go above 7, player 1 wants to go below 0
    int OpponentBoundary = playerTurn == 0 ? 7 : 0;
    bool offOpponentLedge = playerTurn == 0 ? targetY > OpponentBoundary : targetY < OpponentBoundary;
    if (offOpponentLedge) {
        downloadLink(playerTurn, *linkRef);
        removeLink(currentCell);
        linkRef->setCoord(100, 100);
        return true;
    }
    //going out of bounds in X is nada
    if (targetX < 0 || targetX > 7) {
        return false;
    }
    //going out of bounds in your own territory is nada
    if (!offOpponentLedge && (targetY < 0 || targetY > 7)) {
        return false;
    }

    Cell& targetCell = getCell(targetY, targetX);
    
    //Firewall Clause
    //check if the cell has a firewall
    if (targetCell.firewall == true) {
        //check if the firewall is owned by the other player
        if (targetCell.build->getPlayerId() != playerTurn) {
            //reveal the link if the firewall is owned by the other player
            targetCell.link->reveal();
            //check if the link is a virus
            if (targetCell.link->getType() == "virus") {
                //download the virus
                getPlayer(playerTurn).download(false);
                //remove the link
                removeLink(targetCell);
                //set the link's coordinates to 100, 100
                linkRef->setCoord(100, 100);
                //return true
                return true;
            }
        }
    }
    //Unoccupied Clause
    //check if the target cell has no link
    if (targetCell.link == nullptr) {                
        //check if the cell is a server and is owned by the current player
        if (targetCell.server && targetCell.build->getPlayerId() != playerTurn) {
            int OpponentServerId = targetCell.build->getPlayerId();
            //make opponent download the link
            downloadLink(OpponentServerId, *linkRef);
            //remove the link
            removeLink(currentCell);
            //set the link's coordinates to 100, 100
            linkRef->setCoord(100, 100);
            //return true
            return true;
        }
        //otherwise, remove the link from the current Cell and set the target cell's link to the current link
        else {
            removeLink(currentCell);
            targetCell.link = linkRef;
            linkRef->setCoord(targetY, targetX);
            //return true
            return true;
        }
    }
    //Fight Clause
    else if (targetCell.link != nullptr && targetCell.link->getOwnerId() != playerTurn) {
        Link* targetLink = targetCell.link;
        if (linkRef->fightWon(*targetLink)) {
            //target link loses, current player downloads target link
            cout << "FIGHT WON" << endl;
            cout << "targetLink: " << targetLink->getType() << endl;
            removeLink(currentCell);
            targetLink->setCoord(100, 100);
            targetCell.link = linkRef;
            linkRef->setCoord(targetY, targetX);
            downloadLink(playerTurn, *targetLink);
            return true;
        } else {
            //linkRef loses, other player downloads linkRef
            cout << "FIGHT LOST" << endl;
            cout << "linkRef: " << linkRef->getType() << endl;
            removeLink(currentCell);
            linkRef->setCoord(100, 100);
            downloadLink(targetLink->getOwnerId(), *linkRef);
            return true;
        }
    }
    return false;
}

bool Game::moveLink(size_t x, size_t y, Link* linkRef, char direction) { 
    int travelDistance = linkRef->getTravelDistance();
    int otherPlayerNum = (playerTurn == 0) ? 1 : 0;

    // Check link is owned by 
    if(linkRef->getOwnerId() != playerTurn) {
        cout << "LINK IS NOT OWNED BY CURRENT PLAYER" << endl;
        return false;
    }
    //check if the link is active
    if (!linkRef->getActive()) {
        cout << "LINK IS OFF THE BOARD" << endl;
        return false;
    }

    // Check if allowed to move link
    if (linkRef->getOwnerId() != playerTurn)
    {
        cout << "INVALID LINK!" << endl;
        return false;
    }

    // Check which direction to move in
    switch(direction) {
        case 'u':
            //check if the cell is out of bounds
            if(moveLinkHelper(y-travelDistance, x, linkRef)) {
                return true;
            }
            break;
        case 'd':
            if(moveLinkHelper(y+travelDistance, x, linkRef)) {
                return true;
            }
            break;
        case 'l':
            if(moveLinkHelper(y, x-travelDistance, linkRef)) {
                return true;
            }
            break;
        case 'r':
            if(moveLinkHelper(y, x+travelDistance, linkRef)) {
                return true;
            }
            break;
        default:
            cout << "INVALID MOVEMENT!" << endl;
            return false;
    }

    // If we are here direction cell was out of bounds
    // return invalid movement
    cout << "INVALID MOVEMENT!" << endl;
    return false;
}

void Game::removeLink(Cell& target) {
    target.link = nullptr;
}

void Game::endTurn() {
    playerTurn++;
    playerTurn %= players.size();
    playerCastedAbility = false;
    playerMovedLink = false;
    // cout << "ENDING TURN" << endl;
}

void Game::win(int playerNum) {
    cout << "Player " << playerNum+1 << " wins!" << endl;
    gameOver = true;
}

void Game::loss(int playerNum) { //don't need this
    cout << "Player " << playerNum+1 << " loses!" << endl;
    gameOver = true;
}

// displays abilities in the following manner:
// id: AbilityName Availability
// e.g.
// 1: Link Boost AVAILABLE
// 2: Download UNAVAIABLE
// NEEDS TO CHANGE
void Game::displayAbilities(int playerNum) {
    for (int i = 0; i < 5; i++) {
        Ability& a = getPlayer(playerNum).getAbility(i);
        cout << i+1 << ": "
            << a.getName() << "  ";
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
        char l;
        ss >> l;
        Link& linkRef = getLink(l);
        int x = linkRef.getX();
        int y = linkRef.getY();
        char direction;
        ss >> direction;
        if (moveLink(x, y, &linkRef, direction)) {
            Game::endTurn();
        }
    } 
    else if(action == "ability" && !playerCastedAbility) {
        int abilityNum;
        ss >> abilityNum;
        Ability &a = getPlayer(playerTurn).getAbility(abilityNum);
        string abilityName = a.getName();
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
        if (castAbility(abilityNum,getCell(x, y))) {
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
    int otherPlayerNum = (playerTurn == 0) ? 1 : 0;

    cout << "playerTurn" << playerTurn << endl;

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
        cout << "Player " << playerTurn+1 << " turn: ";
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
        if (!useSequence) {
            getline(cin, command);
            runCommand(command);
            checkWin();
        } else {
            runCommand(command);
            checkWin();
        }

        playerMovedLink = false;
        // cout << "CURRENT PLAYER " << playerTurn << endl;
        // playerTurn = (playerTurn == 0) ? 1 : 0;
        // cout << "SWITCHING PLAYERS TO " << playerTurn<< endl;
    }

}

Player &Game::getPlayer(int playerNum) const {
    // cout << "Getting Player Number: " << playerNum << endl;
    return *players[playerNum];
}