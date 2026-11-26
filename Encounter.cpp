#include "Encounter.h"
#include <stdexcept>

//chance of catching pokemon is 60%, change if needed. currently no dynamic catch chance 
const int kCatchChancePercent = 60;


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
//throws logic_error if the operation is invalid (no region selected or encounter already active)
bool Encounter::start()
{
    if (region == nullptr) {
        throw std::logic_error("Choose a region before exploring.");
    }
    if (isActive()) {
        throw std::logic_error("An encounter is already active.");
    }

    wildPokemon = Pokemon((*region).selectRandomPokemon());
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


const Region* Encounter::getRegion() const { return region; }

CatchResult Encounter::attemptCatch(Pokedex& pokedex)
{
    if (!isActive()) {
        return CatchResult::NoActiveEncounter;
    }

    long roll = randomInRange<long>(0, 99);   //roll is 0 to 99
    if (roll < kCatchChancePercent) {         //0-59 = caught (60% chance)
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