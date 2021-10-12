#include "Treasure.h"

void Treasure::setWeight(const double weightInPounds) {
    treasureWeight.setInPounds(weightInPounds);
}

void Treasure::setVolume(const double volumeInGallons) {
    treasureVolume.setInGallons(volumeInGallons);
}

bool Treasure::isPure(const double expectedDensity, const double tolerance) {
    // Density equation. (density = weight / volume)
    double density = treasureWeight.getInGrams() 
                            / treasureVolume.getInCubicCentimeters();
    
    // Calculate the percantage tolerance above and 
    // below the expected density.
    double minDensity = expectedDensity * (1 - tolerance);
    double maxDensity = expectedDensity * (1 + tolerance);

    // Return 'true' if treasure's density is within 1% of expected density. 
    return (density >= minDensity && density <= maxDensity);
}