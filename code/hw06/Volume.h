#pragma once

class Volume {
    double volumeInCC = 0.0;
    // Gallons to liters multiplier
    static constexpr double GALLONS_TO_LITERS = 3.785; 
    // Liters to cubic centimeters multiplier
    static constexpr double LITERS_TO_CC = 1000; 
public:
    double getInCubicCentimeters() const { return volumeInCC; }
    void setInGallons(const double volumeInGallons);
};

