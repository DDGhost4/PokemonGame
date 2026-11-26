//Pokemon.h (class definition)
#pragma once
#include <string>
#include <ostream>   //needed for the << overload

class Pokemon {
    std::string name;
public:
    Pokemon(std::string n = ""); //constructor with default name
    std::string getName() const; //getter for name
};

//operator overload: lets a Pokemon be printed or saved with <<
std::ostream& operator<<(std::ostream& out, const Pokemon& p);