#include "Pokemon.h"


Pokemon::Pokemon(std::string n) : name(n) {}
std::string Pokemon::getName() const { return name; }

//prints the pokemon's name, works with cout and with file streams
std::ostream& operator<<(std::ostream& out, const Pokemon& p) {
    out << p.getName();
    return out;
}