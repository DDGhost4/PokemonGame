#pragma once
#include "Pokedex.h"
#include "Pokemon.h"
#include "Region.h"
#include <optional> //for optional wildPokemon

//enum is needed so names of catch results can be used instead of numbers
enum CatchResult {
    Caught,
    Failed,
    NoActiveEncounter
};

//encounter class; manages the current encounter with a wild pokemon in a specific region
class Encounter {
public:
    Encounter(Region* r = nullptr);

    //region cannot be changed while a wild pokemon is active
    bool setRegion(Region* r); 
    bool start();
    bool isActive() const;
    const Pokemon* getWildPokemon() const;
    const Region* getRegion() const;


    //pokemon enters pokedex if caught, otherwise encounter continues
    CatchResult attemptCatch(Pokedex& pokedex);
    bool flee();

private:
    Region* region;                     // non-owning; the selected region outlives the encounter
    std::optional<Pokemon> wildPokemon; //hold wild pokemon if encounter is active, otherwise empty
};
