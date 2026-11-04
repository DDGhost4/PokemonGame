#include "Pokemon.h"

Pokemon::Pokemon(std::string n) : name(n) {}
std::string Pokemon::getName() const { return name; }
