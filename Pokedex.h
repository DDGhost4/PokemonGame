//Pokedex.h (class definition)
#pragma once
#include <vector>
#include <string>
#include "Pokemon.h"

class Pokedex{
    //vector where caught Pokemon are stored
    std::vector<Pokemon> caught;
public:
    void add(const Pokemon& p);         //adds a Pokemon to the Pokedex
    void display() const;               //displays the names of all caught Pokemon

    //getter for caught Pokemon
    const std::vector<Pokemon>& getCaught() const { return caught; }

    //persistence: 
    bool save(const std::string& filename) const;  // true if saved
    bool load(const std::string& filename);        // true if loaded
};
