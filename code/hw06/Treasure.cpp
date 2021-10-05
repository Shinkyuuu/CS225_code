#include <iostream>
#include "Treasure.h"
using namespace std;


void Treasure::setWeight(const double weightInPounds) {
    treasureWeight.setInPounds(weightInPounds);
}

void Treasure::setVolume(const double volumeInGallons) {
    treasureVolume.setInGallons(volumeInGallons);
}

bool Treasure::isPure(const double expectedDensity, const double tolerance) {
    double density = treasureWeight.getInGrams() / 
                                treasureVolume.getInCubicCentimeters();
    
    double minDensity = expectedDensity * (1 - tolerance);
    double maxDensity = expectedDensity * (1 + tolerance);

    return (density >= minDensity && density <= maxDensity);
}