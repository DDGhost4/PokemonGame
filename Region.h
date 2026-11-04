//Region.h, Region1.h, Region2.h (class definition)

#pragma once
#include <string>
 
class Region {                                          // abstract base
public:
    virtual ~Region() = default;
    virtual std::string rollSpecies(int roll) const = 0;  // pure virtual
};
 
//publicly derived region classes
class Forest : public Region {
public:
    std::string rollSpecies(int roll) const override;
};
 
class Cave : public Region {
public:
    std::string rollSpecies(int roll) const override;
};
 