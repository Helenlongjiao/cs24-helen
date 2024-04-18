#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>

int main() {
    Board board;
    std::string line;
    while(std::getline(std::cin, line)){
        Move move(line);
        if(board.add(move) == 0){
            break;
        }
    }
}
