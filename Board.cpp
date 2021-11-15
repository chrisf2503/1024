#include <iostream>
#include "Board.hpp"

Board::Board(){
    numCols = 3;
    numRows = 3;
    max = 0;
    target = 32;
    panel[3][3];
    panel = new int*[3];
    for(int i = 0; i < 3; i++){
        panel[i] = new int[3];
    }//*/
}
Board::Board(int m){
    numRows = m;
    numCols = m;
    max = 0;
    target = 32;
    panel[m][m];
    panel = new int*[m];
    for(int i = 0; i < m; i++){
        panel[i] = new int[m];
    }//*/
}
Board::Board(int m, int n){
    numRows = m;
    numCols = n;
    max = 0;
    target = 32;
    panel = new int*[m];
    for(int i = 0; i < m; i++){
        panel[i] = new int[n];
    }//*/
}
Board::~Board(){
    delete panel;
}
void Board::setGoal(int goal){
    this->target = goal;
}
void Board::print() const{
    std::cout << "+----+----+----+\n";
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            std::cout << "|   " << panel[i][j]; 
        }
        std::cout << "|\n+----+----+----+\n";
    }
}


