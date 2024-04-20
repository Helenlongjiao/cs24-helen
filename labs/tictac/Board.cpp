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
        std::cout<<"Game in progress: New game.\n";
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
        std::cout << "Game over: O wins.\n";
        return 0;
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
        std::cout << "Game over: X wins.\n";
        return 0;
    }

    if(step == 9){
        std::cout << "Game over: Draw.\n";
        return 0;
    }
    else if(*square[step - 1] == 'O'){
        std::cout << "Game in progress: X's turn.\n";
    }
    else{
        std::cout << "Game in progress: O's turn.\n";
    }
    return 0;
}

