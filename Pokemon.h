//Pokemon.h (class definition)
#pragma once
#include <string>
 
class Pokemon {
    std::string name;
public:
    Pokemon(std::string n = "");
    std::string getName() const;
};
 