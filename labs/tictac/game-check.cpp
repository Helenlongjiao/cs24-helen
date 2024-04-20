#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>

int main() {
    Board board;
    std::string line;
    while(std::getline(std::cin, line)){
        // if (line.empty()) {
        //     break;
        // }
        try{
            Move move(line);
        }
        catch(const ParseError& e){
            std::cout<<"Parse error.\n";
            return 1;
        }
        try{
            board.add(line);
        }
        catch(const InvalidMove& e){
            std::cout<<"Invalid move.\n";
            return 2;
        }
    }
    int gameStatus = board.status();
    if(gameStatus == 0){
        std::cout<<"Game in progress: New game.\n";
    }
    else if(gameStatus == 1){
        std::cout << "Game over: O wins.\n";
    }
    else if(gameStatus == 2){
        std::cout << "Game over: X wins.\n";
    }
    else if(gameStatus == 3){
        std::cout << "Game over: Draw.\n";
    }
    else if(gameStatus == 4){
        std::cout << "Game in progress: X's turn.\n";
    }
    else if(gameStatus == 5){
        std::cout << "Game in progress: O's turn.\n";
    }
    return 0;
}
