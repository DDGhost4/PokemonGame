#include "Encounter.h"

#include <random> //for random number generation

//chance of catching pokemon is 60%, change if needed. currently no dynamic catch chance 
constexpr int kCatchChancePercent = 60;


Encounter::Encounter(Region* region)
    : region(region)
{
}

bool Encounter::setRegion(Region* region) noexcept
{
    if (isActive()) {
        return false;
    }

    this->region = region;
    return true;
}

bool Encounter::start()
{
    if (region == nullptr || isActive()) {
        return false;
    }

    wildPokemon.emplace(region->selectRandomPokemon());
    return true;
}

bool Encounter::isActive() const noexcept
{
    return wildPokemon.has_value();
}

const Pokemon* Encounter::getWildPokemon() const noexcept
{
    return wildPokemon ? &*wildPokemon : nullptr;
}

const Region* Encounter::getRegion() const noexcept
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
bool Encounter::flee() noexcept
{
    if (!isActive()) {
        return false;
    }

    wildPokemon.reset(); //clear wildPokemon to end encounter
    return true;
}
