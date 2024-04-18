#include "Errors.h"
#include "Move.h"
#include <sstream>
#include <iostream>

// Space for implementing Move functions.

Move::Move(const std::string& input){
    if(!std::isdigit(input[0])){
        throw ParseError("first int error.\n");
    }
    if(input[1] != ' ' || input[3] != ' '){
        throw ParseError("missing space.\n");
    }
    std::istringstream iss(input);
    iss >> number >> player >> row_char >> column;
    for(int i = 0; i < input.size(); ++i){
        if(input[i] == player){
            if(input[i + 1] != ' '){
                throw ParseError("missing space.\n");
            }
        }
        if(input[i] == row_char){
            if(input[i + 1] - '0' != column){
                throw ParseError("invalid column.\n");
            }
        }
        if(input[i] - '0' == column){
            if(input[i + 1] != ' ' && input.find('#') != std::string::npos){
                throw ParseError("missing space.\n");
            }
        }
    }
    row_char = std::toupper(row_char);
    row = row_char - 'A' + 1;
    player = std::toupper(player);
    if(input.find('#') != std::string::npos){
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