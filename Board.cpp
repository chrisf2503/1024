#include <iostream>
#include "Board.hpp"
#include <ctime>
#include <cstdlib>

Board::Board(){
    numCols = 3;
    numRows = 3;
    panel = new int*[numRows];
    for(int i = 0; i < numRows; i++){
        panel[i] = new int[numCols];
    }
}
Board::Board(int m){
    numRows = m;
    numCols = m;
    target = 32;
    max = 0;
    panel = new int*[m];
    for(int i = 0; i < m; i++){
        panel[i] = new int[m];
    }
}
Board::Board(int m, int n){
    numRows = m;
    numCols = n;
    panel = new int*[m];
    for(int i = 0; i < m; i++){
        panel[i] = new int[n];
    }
}


