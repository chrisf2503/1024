#include <iostream>
#include "Board.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

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
/*Board::~Board(){
    for(int i = 0; i < numRows; i++){
        delete[] panel[i];
        panel[i] = nullptr;
    }
    delete[] panel;
    panel = nullptr;
}*/
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
        std::cout << "|\n+----+----+----+\n";
    }
}
bool Board::noAdjacentSameValue() const{
    for(int i = 0; i < numRows; i++){    
        for(int j = 0; j < numCols-1; i++){
            if(panel[i][j] == panel[i][j+1]){
                return false;
            }
        }
    }
    for(int i = 0; i < numCols; i++){
        for(int j = 0; j < numRows-1; j++){
            if(panel[i][j] == panel[i+1][j]){
                return false;
            }
        }
    }
    return true;
}//*/
void Board::selectRandomCell(int& row, int& col){
    int countZero = 0;
    std::vector<int*> cell;
    int points[2];
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            if(panel[i][j] == 0){
                countZero++;
                points[0]=i;
                points[1]=j;
                cell.push_back(points);
            }
        }
    }
    if(countZero == 0){
        if(noAdjacentSameValue() == true && max < target){
            std::cout << "Game over. Try again." << '\n';
            exit(0);
        }
        else{
            return;
        }
    }
    if (cell.size() != 0){
        int ran = rand()%cell.size()+0;
        panel[cell[ran][0]][cell[ran][1]] = 1;
        print();
    }
    if(noAdjacentSameValue()){
        std::cout << "Game over. Try again." << '\n';
        exit(0);
    }

}