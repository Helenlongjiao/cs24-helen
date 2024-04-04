#include <iostream>
#include <string>

int main(int argc, char* argv[]){
    if(argc != 2){
        std::cout<<"USAGE: censor [length]";
        return 1;
    }
    std::string input;
    std::getline(std::cin, input);
    size_t count1 = 0;
    size_t count2 = 0;
    size_t first = 0;
    while(count2 <= input.size()){
        while(input[count1] == ' '){
            count1 ++;
            count2 = count1;
            first = count1;
        }
        if(input[count2] != ' ' && count2 < input.size()){
            count2 ++;
        }
        else{
            int diff = count2 - count1;
            if(diff != std::stoi(argv[1])){
                if(count1 != first){
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