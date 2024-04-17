#include "Errors.h"
#include "Move.h"
#include <sstream>

// Space for implementing Move functions.
Move::Move(const std::string& input){
    std::istringstream iss(input);
    iss >> number >> player >> row_char >> column;
    row_char = std::toupper(row_char);
    row = row_char - 'A' + 1;
    if(input.find('#')){
        iss >> comment;
    }
    else{
        comment = "";
    }
}

std::string Move::to_string() const{
    std::string output;
    if((number >= 1 && number <= 9) 
        && (player == 'o' || player == 'O' || player == 'x' || player == 'X')
        && (row >= 1 && row <= 3)
        && (column  >= 1 && column <= 3 )){
            output.append(std::to_string(number));
            output.append(" ");
            output += (std::toupper(player));
            output.append(" ");
            output += std::toupper(row_char);
            output.append(std::to_string(column));
            if(comment != ""){
                output.append(" ");
                output += comment;
            }
            return output;
        }
        else{
            return ""; //how to throw an error to the move check if this is an invalid move?
        }
}