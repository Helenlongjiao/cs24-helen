#ifndef BOARD_H
#define BOARD_H

#include "Move.h"

// I recommended writing a Board class to manage your game state.
// Here's some space for the class definition; member functions go in Board.cpp.

struct Board{
private:
    Move* move;
    int step;
public:
    Board();
    Board(const Board& other);
    ~Board();
    int add(const Move* newMove);
};
#endif
