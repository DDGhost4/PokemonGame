#include "Pokedex.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <stdexcept>

//
void Pokedex::add(const Pokemon& p) { caught.push_back(p); }

void Pokedex::display() const {
    for (const auto& p : caught) std::cout << "Caught: " << p << "\n";
}

//persistence: 
bool Pokedex::save(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) return false;

    out << "POKEDEX1\n";               //header so we can recognize our own file
    for (const auto& p : caught) {
        out << p << "\n";              //one name per line
    }
    return out.good();
}

//throws runtime_error if the file is missing or damaged; current data is kept on failure
bool Pokedex::load(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        throw std::runtime_error("Could not open save file: " + filename);
    }

    std::string line;
    if (!std::getline(in, line) || line != "POKEDEX1") {
        throw std::runtime_error("Save file has a wrong or missing header.");
    }

    std::vector<Pokemon> temp;         //read into a temp list first
    while (std::getline(in, line)) {
        if (line.empty() || line.size() > 30) {
            throw std::runtime_error("Save file has an empty or too long name.");
        }
        for (char c : line) {
            if (!std::isalpha(static_cast<unsigned char>(c)) && c != ' ' && c != '-') {
                throw std::runtime_error("Save file has a bad character in: " + line);
            }
        }
        temp.push_back(Pokemon(line));
    }

    caught = temp;                     //only replaced if everything above succeeded
    return true;
}