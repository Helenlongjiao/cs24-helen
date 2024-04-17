#include "Errors.h"
#include "Move.h"
#include <sstream>

// Space for implementing Move functions.

Move::Move(){
    number = 0;
    player = 'O';
    row_char = 'A';
    column = 0;
    row = 0;
    comment = "no comment";
}

Move::Move(const std::string& input){
    std::istringstream iss(input);
    iss >> number >> player >> row_char >> column;
    row_char = std::toupper(row_char);
    row = row_char - 'A' + 1;
    player = std::toupper(player);
    if(input.find('#')){
        iss >> comment;
    }
    else{
        comment = "";
    }
    if(number < 1 || number > 9){
        throw ParseError("number out of bound\n");
    }
    if(player != 'o' && player != 'O' && player != 'x' && player != 'X'){
        throw ParseError("invalid player\n");
    }
    if(row < 1 || row > 3){
        throw ParseError("invalid row\n");
    }
    if(column < 1 || column > 3){
        throw ParseError("invalid column\n");
    }
}

std::string Move::to_string() const{
    std::string output;
    // if((number >= 1 && number <= 9) 
    //     && (player == 'o' || player == 'O' || player == 'x' || player == 'X')
    //     && (row >= 1 && row <= 3)
    //     && (column  >= 1 && column <= 3 )){
            output.append(std::to_string(number));
            output.append(" ");
            output += player;
            output.append(" ");
            output += row_char;
            output.append(std::to_string(column));
            if(comment != ""){
                output.append(" ");
                output += comment;
            }
            return output;
        // }
        // else{
        //     throw ParseError(to_string()); //how to throw an error to the move check if this is an invalid move?
        // }
}