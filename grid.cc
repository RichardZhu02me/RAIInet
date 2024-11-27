#include "grid.h"

using namespace std;


Grid::Grid() {
            theBoard = vector<vector<Cell>>(8, vector<Cell>(8));
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    theBoard[i][j].link = nullptr;
                }
            }
}

Link* Grid::getLink(size_t row, size_t col) {
    return theBoard[row][col].link;
}  

Grid::Cell& Grid::getCell(size_t row, size_t col){
    return theBoard[row][col];
}
