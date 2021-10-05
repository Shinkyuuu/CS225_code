#pragma once
class Volume {
    double volumeInCC = 0.0;
    const double GALLONS_TO_LITERS = 3.785;
    const double LITERS_TO_CC = 1000;
public:
    double getInCubicCentimeters() const { return volumeInCC; }
    void setInGallons(const double volumeInGallons);
};

