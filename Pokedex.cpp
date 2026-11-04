//Pokedex.cpp
#include "Pokedex.h"
#include <iostream>

void Pokedex::add(const Pokemon& p) { caught.push_back(p); }
void Pokedex::display() const {
    for (const auto& p : caught) std::cout << "Caught: " << p.getName() << "\n";
}
 