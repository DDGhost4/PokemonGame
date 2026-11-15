#pragma once

#include <string>
#include <vector>

// A region owns its encounter table and the species available there.
class Region {
public:
    virtual ~Region() = default;

    const std::string& getName() const noexcept;
    const std::vector<std::string>& getAvailablePokemon() const noexcept;
    std::string selectRandomPokemon() const;

    // Deterministic entry point for a roll from 0 through 99.
    virtual std::string rollSpecies(int roll) const = 0;

protected:
    struct EncounterEntry {
        std::string species;
        int weight;
    };

    Region(std::string name, std::vector<EncounterEntry> encounterTable);
    std::string speciesForRoll(int roll) const;

private:
    std::string name;
    std::vector<EncounterEntry> encounterTable;
    std::vector<std::string> availablePokemon;
};

class Forest : public Region {
public:
    Forest();
    std::string rollSpecies(int roll) const override;
};

class Cave : public Region {
public:
    Cave();
    std::string rollSpecies(int roll) const override;
};
