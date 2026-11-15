#pragma once

#include "Pokedex.h"
#include "Pokemon.h"
#include "Region.h"

#include <optional>

enum class CatchResult {
    Caught,
    Failed,
    NoActiveEncounter
};

class Encounter {
public:
    explicit Encounter(Region* region = nullptr);

    // The region cannot be changed while a wild Pokemon is active.
    bool setRegion(Region* region) noexcept;
    bool start();
    bool isActive() const noexcept;
    const Pokemon* getWildPokemon() const noexcept;
    const Region* getRegion() const noexcept;

    // A successful catch is the only way the Pokemon enters the Pokedex.
    CatchResult attemptCatch(Pokedex& pokedex);
    bool flee() noexcept;

private:
    Region* region; // non-owning; the selected region outlives the encounter
    std::optional<Pokemon> wildPokemon;
};
