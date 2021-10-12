#pragma once

class Weight {
    double weightInGrams = 0.0;
    // Pounds to ounces multiplier
    static constexpr double POUNDS_TO_OUNCES = 16.0; 
    // Ounces to grams multiplier
    static constexpr double OUNCES_TO_GRAMS = 28.35; 
public:
    double getInGrams() const { return weightInGrams; }
    void setInPounds(const double weightInPounds);
};

