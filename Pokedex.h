//Pokedex.h (class definition)
#pragma once
#include <vector>
#include "Pokemon.h"
 
class Pokedex{
    std::vector<Pokemon> caught;
public:
    void add(const Pokemon& p);
    void display() const;
};