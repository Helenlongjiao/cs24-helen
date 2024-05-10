#include "Person.h"
#include "GenePool.h"

// Person Member Functions

Person::Person(std::string name, std::string gender, Person* motherPtr, Person* fatherPtr){
    this->mem_name = name;
    this->mem_gender = gender;
    mem_mother = motherPtr;
    mem_father = fatherPtr;
    if(mem_father != nullptr){
        mem_father->mem_children.insert(this);
    }
    if(mem_mother != nullptr){
        mem_mother->mem_children.insert(this);
    }
}

Person::~Person(){}

const std::string& Person::name() const{
    return mem_name;
}
Gender  Person::gender() const{
    Gender retGender;
    if(mem_gender == "male"){
        retGender = Gender::MALE;
    }
    else if(mem_gender == "female"){
        retGender = Gender::FEMALE;
    }
    else{
        retGender = Gender::ANY;
    }
    return retGender;
}

Person* Person::mother(){
    return mem_mother;
}
Person* Person::father(){
    return mem_father;
}

std::set<Person*> Person::ancestors(PMod pmod){
    std::set<Person*> empty; //not written
    return empty;
}
std::set<Person*> Person::aunts(PMod pmod, SMod smod){
    std::set<Person*> empty; //not written
    return empty;
}

std::set<Person*> Person::brothers(PMod pmod, SMod smod){
    std::set<Person*> output;
    std::set<Person*> mem_siblings = siblings();
    for (auto it = mem_siblings.begin(); it != mem_siblings.end(); ++it) {
        if(this->gender() == Gender::MALE){
            output.insert(*it);
        }
    }
    return output;
}

std::set<Person*> Person::children(){
    return mem_children;
}

std::set<Person*> Person::cousins(PMod pmod, SMod smod){
    std::set<Person*> empty; //not written
    return empty;
}

std::set<Person*> Person::daughters(){
    std::set<Person*> output;
    for (auto it = mem_children.begin(); it != mem_children.end(); ++it) {
        if(this->gender() == Gender::FEMALE){
            output.insert(*it);
        }
    }
    return output;
}

std::set<Person*> Person::descendants(){
    std::set<Person*> empty; //not written
    return empty;
}

std::set<Person*> Person::grandchildren(){
    std::set<Person*> output;
    for(Person* person: mem_children){
        output.merge(person->mem_children);
    }
    return output;
}

std::set<Person*> Person::granddaughters(){
    std::set<Person*> output;
    std::set<Person*> grandc = grandchildren();
    for (auto it = grandc.begin(); it != grandc.end(); ++it) {
        if(this->gender() == Gender::MALE){
            output.insert(*it);
        }
    }
    return output;
}

std::set<Person*> Person::grandfathers(PMod pmod){
    std::set<Person*> output;
    if(mem_father->mem_father != nullptr && pmod != PMod::MATERNAL){
        output.insert(mem_father->mem_father);
    }
    return output;
}

std::set<Person*> Person::grandmothers(PMod pmod){
    std::set<Person*> output;
    if(mem_mother->mem_mother != nullptr && pmod != PMod::PATERNAL){
        output.insert(mem_mother->mem_mother);
    }
    return output;
}

std::set<Person*> Person::grandparents(PMod pmod){
    std::set<Person*> output;
    if(pmod == PMod::MATERNAL){
        return mem_mother->parents(pmod);
    }
    else if(pmod == PMod::PATERNAL){
        return mem_father->parents(pmod);
    }
    else{
        output.merge(mem_mother->parents(pmod));
        output.merge(mem_father->parents(pmod));
        return output;
    }
}

std::set<Person*> Person::grandsons(){
    std::set<Person*> empty; //not written
    return empty;
}
std::set<Person*> Person::nephews(PMod pmod, SMod smod){
    std::set<Person*> empty; //not written
    return empty;
}
std::set<Person*> Person::nieces(PMod pmod, SMod smod){
    std::set<Person*> empty; //not written
    return empty;
}

std::set<Person*> Person::parents(PMod pmod){
    std::set<Person*> output;
    if(mem_mother != nullptr && pmod != PMod::PATERNAL){
        output.insert(mem_mother);
    }
    if(mem_father != nullptr && pmod != PMod::MATERNAL){
        output.insert(mem_father);
    }
    return output;
}

std::set<Person*> Person::siblings(PMod pmod, SMod smod){
    std::set<Person*> output;
    if(pmod == PMod::MATERNAL){
        if(mem_mother != nullptr){
            output.merge(mem_mother->mem_children);
        }
    }
    if(pmod == PMod::PATERNAL){
        if(mem_father != nullptr){
            output.merge(mem_father->mem_children);
        }
    }
    else{
        if(mem_mother != nullptr){
            output.merge(mem_mother->mem_children);
        }
        if(mem_father != nullptr){
            output.merge(mem_father->mem_children);
        }
    }
    // return output;
    if(smod == SMod::HALF){
        for(Person* person: output){
            if(person->mem_father != nullptr && person->mem_mother != nullptr
            && person->mem_father == mem_father && person->mem_mother == mem_mother){
                output.erase(person);
            }
        }
    }
    else if(smod == SMod::FULL){
        for(Person* person: output){
            if(person->mem_father != mem_father || person->mem_mother != mem_mother
            || person->mem_father == nullptr || person->mem_mother == nullptr){
                output.erase(person);
            }
        }
    }
    output.erase(this);
    return output;
}

std::set<Person*> Person::sisters(PMod pmod, SMod smod){
    std::set<Person*> output;
    std::set<Person*> mem_siblings = siblings();
    for (auto it = mem_siblings.begin(); it != mem_siblings.end(); ++it) {
        if(this->gender() == Gender::FEMALE){
            output.insert(*it);
        }
    }
    return output;
}

std::set<Person*> Person::sons(){
    std::set<Person*> output;
    for (auto it = mem_children.begin(); it != mem_children.end(); ++it) {
        if(this->gender() == Gender::MALE){
            output.insert(*it);
        }
    }
    return output;
}

std::set<Person*> Person::uncles(PMod pmod, SMod smod){
    std::set<Person*> empty; //not written
    return empty;
}