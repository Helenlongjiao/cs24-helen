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
    currPlayer = 'n';
    std::cout << "Game in progress: New game.\n";
}

Board::~Board(){

}

int Board::add(const Move& newMove){
    //check if it's a valid move
    if(step == 0){
        currPlayer = newMove.player;
    }
    else if(newMove.player == currPlayer){
        throw InvalidMove("You should switch player.\n");
    }
    if(newMove.number != step + 1){
        throw InvalidMove("Invalid step number.\n");
    }
    if(square[newMove.row][newMove.column] != 'n'){
        throw InvalidMove("this square is claimed.\n");
    }

    //first add newMove to square
    square[newMove.row - 1][newMove.column - 1] = newMove.player;

    //check status

    //column:
    std::cout<<square[0][0]<<square[0][1]<<square[0][2]<<'\n'<<square[1][0]<<square[1][1]<<square[1][2]<<'\n'<<square[2][0]<<square[0][1]<<square[2][2]<<'\n';
    if((square[0][newMove.column - 1] == newMove.player 
        && square[1][newMove.column - 1] == newMove.player 
        && square[2][newMove.column - 1] == newMove.player)
        ||
        (square[newMove.row - 1][0] == newMove.player
        && square[newMove.row - 1][1] == newMove.player
        && square[newMove.row - 1][2] == newMove.player)
        ||
        square[0][0] == square[1][1] == square[2][2]
        ||
        square[0][2] == square[1][1] == square[2][0]){
        std::cout << "Game over: " << newMove.player << " wins.\n";
        return 0;
    }

    step ++;
    if(step == 8){
        std::cout << "Game over: Draw.\n";
        return 0;
    }
    else if(newMove.player == 'O'){
        std::cout << "Game in progress: X's turn.\n";
        currPlayer = newMove.player;
        return 1;
    }
    else{
        std::cout << "Game in progress: O's turn.\n";
        currPlayer = newMove.player;
        return 1;
    }
    return 2;
}
