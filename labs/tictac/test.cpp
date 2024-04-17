#include <iostream>
#include <sstream>
#include <string>

int main(){
    std::string input;
    std::getline(std::cin, input);
    int  number;
    char player;
    int  row;
    int  column;

    char row_char;
    std::istringstream iss(input);
    iss >> number >> player >> row_char >> column;
    row = row_char - 'A' + 1;
    std::cout<<number<<'/'<<player<<'/'<<row<<'/'<<column;
}

