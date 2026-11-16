//Pokemon.h (class definition)
#pragma once
#include <string>
 
class Pokemon {
    std::string name;
public:
    Pokemon(std::string n = ""); //constructor with default name
    std::string getName() const; //getter for name
};