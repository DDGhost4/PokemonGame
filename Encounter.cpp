//Encounter.cpp 
#include "Encounter.h"
 
Encounter::Encounter(Region* r) : region(r) {}
void Encounter::setRegion(Region* r) { region = r; }
void Encounter::run(int roll, Pokedex& dex) {
    Pokemon wild(region->rollSpecies(roll));   // virtual call
    dex.add(wild);
}
 