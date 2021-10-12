#pragma once
#include "Weight.h"
#include "Volume.h"

class Treasure {
    Weight treasureWeight;
    Volume treasureVolume;
public:
    static constexpr double GOLD = 19.3; // Gold density
    static constexpr double SILVER = 10.5; // Silver density
    static constexpr double ONE_PERCENT = 0.01;
    static constexpr double TENTH_PERCENT = 0.001;

    void setWeight(const double weightInPounds);
    void setVolume(const double volumeInGallons);
    bool isPure(const double expectedDensity, const double tolerance);
};

