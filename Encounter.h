//Encounter.h (class definition)
#pragma once
#include "Region.h"
#include "Pokemon.h"
#include "Pokedex.h"
 
class Encounter {
    Region* region;   // base pointer to current region
public:
    Encounter(Region* r);
    void setRegion(Region* r);
    void run(int roll, Pokedex& dex);   // spawn a Pokemon and catch it
};
 