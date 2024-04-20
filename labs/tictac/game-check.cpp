#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>

int main() {
    Board board;
    std::string line;
    while(std::getline(std::cin, line)){
        if (line.empty()) {
            break;
        }
        Move move(line);
        try{
            board.add(line);
        }
        catch(const InvalidMove& e){
            std::cout<<"Invalid move.\n";
            return 2;
        }
    }
    board.status();
    return 0;
}
