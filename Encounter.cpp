#include "Encounter.h"
#include <random> //for random number generation

//chance of catching pokemon is 60%, change if needed. currently no dynamic catch chance 
constexpr int kCatchChancePercent = 60;


//constructor: stores region pointer
Encounter::Encounter(Region* r) : region(r) {}


//changes region. only works if there is no active encounter
bool Encounter::setRegion(Region* r) 
{
    if (isActive()) { 
        return false;       //active = no change allowed
    }

    region = r;             //otherwise, change region to new region pointer
    return true;            
}


//picks a random pokemon from region's encounter table and starts encounter
bool Encounter::start()
{
    if (region == nullptr || isActive()) { //if no region is selected or encounter is already active ==> return false
        return false;
    }

    wildPokemon = Pokemon((*region).selectRandomPokemon()); //otherwise, select a random pokemon from the region's encounter table and start encounter
    return true;
}

//determines if encounter is active (if wildPokemon has a value)
bool Encounter::isActive() const
{
    return wildPokemon.has_value();
}

//
const Pokemon* Encounter::getWildPokemon() const
{
    if (isActive()) {
        return &wildPokemon.value(); //return pointer to wildPokemon if encounter is active
    }
    return nullptr;
}


const Region* Encounter::getRegion() const
{
    return region;
}

CatchResult Encounter::attemptCatch(Pokedex& pokedex)
{
    if (!isActive()) {
        return CatchResult::NoActiveEncounter;
    }

    static std::mt19937 generator(std::random_device{}());
    static std::uniform_int_distribution<int> distribution(1, 100);
    if (distribution(generator) <= kCatchChancePercent) {
        pokedex.add(*wildPokemon);
        wildPokemon.reset();
        return CatchResult::Caught;
    }


    return CatchResult::Failed;
}

//flee encounter (does not return true if there is no active encounter)
bool Encounter::flee()
{
    if (!isActive()) {
        return false;
    }

    wildPokemon.reset(); //clear wildPokemon to end encounter
    return true;
}
