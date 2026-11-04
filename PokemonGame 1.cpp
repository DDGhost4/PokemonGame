#include <iostream>
#include "Encounter.h"

int main() {
    Forest forest;
    Cave cave;
    Pokedex dex;
    Encounter enc(&forest);
 
    enc.run(30, dex);          // Forest encounter
    enc.setRegion(&cave);
    enc.run(30, dex);          // Cave encounter
 
    dex.display();
}
