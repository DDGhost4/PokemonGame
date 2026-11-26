#pragma once
#include <string>
#include <vector>
#include <random>   // needed for the random number template

//template: returns a random whole number from low to high (including both)
//it is written here in the header so every file that includes Region.h can use it
template <typename T>
T randomInRange(T low, T high) {
    static std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<T> distribution(low, high);
    return distribution(generator);
}

//region owns its encounter table and the species available there
class Region {
public:
    virtual ~Region() = default;

    const std::string& getName() const;
    const std::vector<std::string>& getAvailablePokemon() const;
    std::string selectRandomPokemon() const;

    //entry point for a roll from 0 through 99.
    virtual std::string rollSpecies(int roll) const = 0;

protected:
    struct EncounterEntry {
        std::string species;
        int weight;
    };

    Region(std::string n, std::vector<EncounterEntry> table);
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