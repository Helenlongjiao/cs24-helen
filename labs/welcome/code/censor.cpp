#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    if(argc != 2){
        std::cout<<"USAGE: censor [length]";
    }
    std::string input;
    std::getline(std::cin, input);
    int count1 = 0;
    int count2 = 0;
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
                for(int i = count1; i < count2; ++i){
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