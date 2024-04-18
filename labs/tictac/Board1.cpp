#include "Errors.h"
#include "Board1.h"
#include "Move.h"
#include <iostream>

// Space for implementing Board functions.

Board::Board(){
    move = new Move[9];   //Q: it's hard to have an empty Move. So how to write the constructor?
    step = 0;
    std::cout<<"Game in progress: New game.\n";
}

Board::Board(const Board& other){

}

Board::~Board(){

}

int Board::add(const Move* newMove){
    //check if it's a valid move
    if((newMove->player == move[step].player)
        || (newMove->number != (move[step].number + 1))
        ){
        throw InvalidMove("Invalid move.\n");
    }
    for(int i = 0; i <= step + 1; ++i){
        if((newMove->column == move[i].column) && (newMove->row == move[i].row)){
            throw InvalidMove("this square is claimed.\n");
        }
    }

    //check status
    for(int i = 0; i <= step; ++i){
        if(newMove->player == move[i].player && newMove->column == move[i].column){
            for(int j = i + 1; j <= step; ++j){
                if(newMove->player == move[i].player && newMove->column == move[i].column){
                    std::cout << "Game over: " << newMove->player << " wins.\n";
                    return 0;
                }
            }
        }
        if(newMove->player == move[i].player && newMove->row == move[i].row){
            for(int j = i + 1; j <= step; ++j){
                if(newMove->player == move[i].player && newMove->row == move[i].row){
                    std::cout << "Game over: " << newMove->player << " wins.\n";
                    return 1;
                }
            }
        }
        if(newMove->player == move[i].player && newMove->column != move[i].column && newMove->row != move[i].row){
            for(int j = i + 1; j <= step; ++j){
                if(newMove->player == move[i].player && newMove->column != move[i].column && newMove->row != move[i].row){
                    std::cout << "Game over: " << newMove->player << " wins.\n";
                    return 1;
                }
            }
        }
    }
    step ++;
    if(step == 8){
        std::cout << "Game over: Draw.\n";
        return 0;
    }
    else if(newMove->player == 'O'){
        std::cout << "Game in progress: X's turn.\n";
        return 0;
    }
    else{
        std::cout << "Game in progress: O's turn.\n";
        return 0;
    }
    return 1;
}
