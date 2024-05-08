#include "GenePool.h"
#include "Person.h"
#include <iostream>
#include <sstream>
#include <iostream>

// GenePool Member Functions

// Build a database of people from a TSV file.

GenePool::GenePool(std::istream& stream){
    std::string line;
    while (std::getline(stream, line)) {
        if (line.empty() || line[0] == '#') {
            continue;
        }
        std::istringstream iss(line);
        std::string name, gender, mother, father;
        std::getline(iss, name,   '\t');
        std::getline(iss, gender, '\t');
        std::getline(iss, mother, '\t');
        std::getline(iss, father, '\t');
        Person* motherPtr;
        Person* fatherPtr;
        if(mother == "???"){
            motherPtr = nullptr;
        }
        else{
            motherPtr = find(mother);
        }
        if(father == "???"){
            fatherPtr = nullptr;
        }
        else{
            fatherPtr = find(father);
        }
        // mymap[name] = Person(name, gender, motherPtr, fatherPtr);
        mymap.emplace(std::make_pair(name, Person(name, gender, motherPtr, fatherPtr)));
    }
}

// Clean it up.
GenePool::~GenePool(){}

// List all the people in the database.
std::set<Person*> GenePool::everyone() const{
    std::set<Person*> output;
    for (auto& pair : mymap){
        output.insert(&pair.second);
    }
    return output;
}

// Find a person in the database by name.
// Return nullptr if there is no such person.
Person* GenePool::find(const std::string& name) const{
    auto it = mymap.find(name);
    if(it == mymap.end()){
        return nullptr;
    }
    else{
        return &it->second;
    }
}