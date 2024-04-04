#include <iostream>
#include <string>

int main(size_t argc, char* argv[]){
    if(argc != 2){
        std::cout<<"USAGE: censor [length]";
    }
    std::string input;
    std::getline(std::cin, input);
    size_t count1 = 0;
    size_t count2 = 0;
    while(count2 < input.size()){
        while(input[count1] == ' '){
            count1 ++;
            count2 = count1;
        }
        if(input[count2] != ' ' && count2 < input.size()){
            count2 ++;
        }
        else{
            if(count2 - count1 != std::stoi(argv[1])){
                if(count1 != 0){
                    std::cout<<' ';
                }
                for(size_t i = count1; i < count2; ++i){
                    std::cout<<input[i];
                }
            }
            count2 ++;
            count1 = count2;
        }
    }
    std::cout<<'\n';
    return 0;
}