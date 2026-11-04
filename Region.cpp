#include "Region.h"

std::string Forest::rollSpecies(int roll) const 
{ return roll < 60 ? "Pidgey" : "Caterpie"; }

std::string Cave::rollSpecies(int roll) const   
{ return roll < 70 ? "Zubat" : "Geodude"; }
