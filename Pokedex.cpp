#include "Pokedex.h"
#include <iostream>
#include <fstream>
#include <cctype>

//
void Pokedex::add(const Pokemon& p) { caught.push_back(p); }

void Pokedex::display() const {
    for (const auto& p : caught) std::cout << "Caught: " << p.getName() << "\n";
}

//persistence: 
bool Pokedex::save(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) return false;

    out << "POKEDEX1\n";               //header so we can recognize our own file
    for (const auto& p : caught) {
        out << p.getName() << "\n";    //one name per line
    }
    return out.good();
}

bool Pokedex::load(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) return false;             // file missing or unreadable

    std::string line;
    if (!std::getline(in, line) || line != "POKEDEX1") {
        return false;                  //wrong or missing header
    }

    std::vector<Pokemon> temp;         //read into a temp list first
    while (std::getline(in, line)) {
        if (line.empty() || line.size() > 30) return false;
        for (char c : line) {
            if (!std::isalpha(static_cast<unsigned char>(c)) && c != ' ' && c != '-') {
                return false;          //bad character: file is malformed
            }
        }
        temp.push_back(Pokemon(line));
    }

    caught = temp;                     //replace real data with the temporary list if everything was successful
    return true;
}
