#include "Region.h"
#include <random>           //std::mt19937, std::random_device, std::uniform_int_distribution
#include <stdexcept>        //std::invalid_argument, std::out_of_range, std::logic_error
#include <unordered_set>    //std::unordered_set (checks for duplicate species in encounter table)
#include <utility>          //std::move


const int kRollCount = 100; //rolls are 0-99

Region::Region(std::string n, std::vector<EncounterEntry> table) : name(std::move(n)), encounterTable(std::move(table)) {
    if (name.empty()) {
        throw std::invalid_argument("region must have a name");
    }
    if (encounterTable.empty()) {
        throw std::invalid_argument("region must have at least one encounter entry");
    }

    int totalWeight = 0;
    std::unordered_set<std::string> seenSpecies;
    availablePokemon.reserve(encounterTable.size());
    for (const EncounterEntry& entry : encounterTable) {
        if (entry.species.empty()) {
            throw std::invalid_argument("region cannot contain an empty pokemon species name");
        }
        if (entry.weight <= 0) {
            throw std::invalid_argument("pokemon encounter weights must be positive");
        }
        if (!seenSpecies.insert(entry.species).second) {
            throw std::invalid_argument("pokemon species can appear only once in a region encounter table");
        }

        totalWeight += entry.weight;
        availablePokemon.push_back(entry.species);
    }

    if (totalWeight != kRollCount) {
        throw std::invalid_argument("region encounter weights must add up to 100");
    }
}

const std::string& Region::getName() const {return name;}

const std::vector<std::string>& Region::getAvailablePokemon() const {return availablePokemon;}

std::string Region::selectRandomPokemon() const {
    static std::mt19937 generator(std::random_device{}());
    static std::uniform_int_distribution<int> distribution(0, kRollCount - 1);
    return rollSpecies(distribution(generator));
}

std::string Region::speciesForRoll(int roll) const
{
    if (roll < 0 || roll >= kRollCount) {
        throw std::out_of_range("region encounter roll must be between 0 and 99");
    }

    int cumulativeWeight = 0;
    for (const EncounterEntry& entry : encounterTable) {
        cumulativeWeight += entry.weight;
        if (roll < cumulativeWeight) {
            return entry.species;
        }
    }

    //constructor enforces a total weight of 100, so this is unreachable
    throw std::logic_error("The region encounter table is invalid.");
}

//forest data
Forest::Forest()
    : Region("Forest", {
          {"Pidgey", 16},
          {"Rattata", 14},
          {"Caterpie", 12},
          {"Weedle", 10},
          {"Oddish", 10},
          {"Bellsprout", 8},
          {"Pikachu", 7},
          {"Paras", 6},
          {"Venonat", 5},
          {"Exeggcute", 5},
          {"Scyther", 2},
          {"Pinsir", 2},
          {"Tangela", 3}
      })
{ 
}

std::string Forest::rollSpecies(int roll) const {
    return speciesForRoll(roll);}

Cave::Cave() 
    : Region("Cave", {
          {"Zubat", 20},
          {"Geodude", 18},
          {"Onix", 12},
          {"Sandshrew", 10},
          {"Diglett", 10},
          {"Machop", 8},
          {"Cubone", 8},
          {"Gastly", 6},
          {"Drowzee", 3},
          {"Mankey", 2},
          {"Clefairy", 2},
          {"Jigglypuff", 1}
      })
{
}

std::string Cave::rollSpecies(int roll) const {
    return speciesForRoll(roll);}
