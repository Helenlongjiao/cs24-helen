#ifndef BOARD_H
#define BOARD_H

#include "Move.h"

// I recommended writing a Board class to manage your game state.
// Here's some space for the class definition; member functions go in Board.cpp.

struct Board{
private:
    char square[3][3];
    int step;
    char curr;
public:
    Board();
    ~Board();
    void add(const Move& newMove);
    int status();
};
#endif
