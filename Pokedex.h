//Pokedex.h (class definition)
#pragma once
#include <vector>
#include <string>
#include "Pokemon.h"

class Pokedex{
    std::vector<Pokemon> caught;
public:
    void add(const Pokemon& p);
    void display() const;
    const std::vector<Pokemon>& getCaught() const { return caught; }

    bool save(const std::string& filename) const;  // true if saved
    bool load(const std::string& filename);        // true if loaded
};
