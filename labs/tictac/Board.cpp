#include "Errors.h"
#include "Board.h"
#include "Move.h"
#include <iostream>

// Space for implementing Board functions.

Board::Board(){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            square[i][j] = 'n';
        }
    }
    step = 0;
    curr = 'n';
}

Board::~Board(){

}

void Board::add(const Move& newMove){
    //check if it's a valid move
    int sta = status();
    if((sta == 1) || (sta == 2) || (sta == 3)){
        throw InvalidMove("The game has ended.\n");
    }
    if(step == 0){
        curr = newMove.player;
    }
    else if(newMove.player == curr){
        throw InvalidMove("You should switch player.\n");
    }
    if(newMove.number != step + 1){
        throw InvalidMove("Invalid step number.\n");
    }
    if(square[newMove.row - 1][newMove.column - 1] != 'n'){
        throw InvalidMove("this square is claimed.\n");
    }

    curr = newMove.player;
    square[newMove.row - 1][newMove.column - 1] = newMove.player;
    step ++;
}

int Board::status(){
    if(step == 0){
        return 0;
    }
    // std::cout<<square[0][0]<<square[0][1]<<square[0][2]<<'\n'<<square[1][0]<<square[1][1]<<square[1][2]<<'\n'<<square[2][0]<<square[2][1]<<square[2][2]<<'\n';
    if(((square[0][0]) == 'O' 
        && (square[1][0]) == 'O' 
        && (square[2][0]) == 'O')
        ||
        ((square[0][1]) == 'O' 
        && (square[1][1]) == 'O' 
        && (square[2][1]) == 'O')
        ||
        ((square[0][2]) == 'O' 
        && (square[1][2]) == 'O' 
        && (square[2][2]) == 'O')
        ||
        ((square[0][0]) == 'O'
        && (square[0][1]) == 'O'
        && (square[0][2]) == 'O')
        ||
        ((square[1][0]) == 'O'
        && (square[1][1]) == 'O'
        && (square[1][2]) == 'O')
        ||
        ((square[2][0]) == 'O'
        && (square[2][1]) == 'O'
        && (square[2][2]) == 'O')
        ||
        ((square[0][0] == square[1][1]) && ( square[1][1] == square[2][2]) && (square[1][1] == 'O'))
        ||
        ((square[0][2] == square[1][1]) && (square[0][2] == square[2][0]) && (square[0][2] == 'O'))
        ){
        return 1;
    }

    if(((square[0][0]) == 'X' 
        && (square[1][0]) == 'X' 
        && (square[2][0]) == 'X')
        ||
        ((square[0][1]) == 'X' 
        && (square[1][1]) == 'X' 
        && (square[2][1]) == 'X')
        ||
        ((square[0][2]) == 'X' 
        && (square[1][2]) == 'X' 
        && (square[2][2]) == 'X')
        ||
        ((square[0][0]) == 'X'
        && (square[0][1]) == 'X'
        && (square[0][2]) == 'X')
        ||
        ((square[1][0]) == 'X'
        && (square[1][1]) == 'X'
        && (square[1][2]) == 'X')
        ||
        ((square[2][0]) == 'X'
        && (square[2][1]) == 'X'
        && (square[2][2]) == 'X')
        ||
        ((square[0][0] == square[1][1]) && ( square[1][1] == square[2][2]) && (square[1][1] == 'X'))
        ||
        ((square[0][2] == square[1][1]) && (square[0][2] == square[2][0]) && (square[0][2] == 'X'))
        ){
        return 2;
    }

    if(step == 9){
        return 3;
    }
    else if(curr == 'O'){
        return 4;
    }
    else{
        return 5;
    }
    return 6;
}

