#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>

int main() {
    Board board;
    std::string line;
    while(std::getline(std::cin, line)){
        Move move(line);
        try{
            if(board.add(move) == 0){
            return 0;
        }
        }
        catch(const InvalidMove& e){
            std::cout<<"Invalid move.\n";
            return 2;
        }
    }
}
