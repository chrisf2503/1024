#include <iostream>
#include "Board.hpp"

Board::Board(){
    numCols = 3;
    numRows = 3;
    max = 0;
    target = 32;
    panel[3][3];
}
Board::Board(int m){
    numRows = m;
    numCols = m;
    max = 0;
    target = 32;
    panel[m][m];
}
Board::Board(int m, int n){
    numRows = m;
    numCols = n;
    max = 0;
    target = 32;
    panel[m][n];
}
Board::~Board(){
    
}
void Board::setTarget(int goal){
    this->target = goal;
}
void Board::print() const{
    for(int i = 0; i < numCols; i++){
        std::cout << "+----";
    }
    std::cout << "+" << std::endl;
    for(int i = 0; i < numRows*2; i++){
        for(int j = 0; j < numCols; j++){
            if(i % 2 == 0){
                std::cout << "|    ";
                if( j == numCols-1){
                    std::cout << "|";
                }
            } 
            else if(i % 2 != 0){
                std::cout << "+----";
                if(j == numCols -1){
                    std::cout << "+";
                }
            }
        }
        std::cout << std::endl;
        //std::cout << "|\n+----+----+----+\n";
    }
}

