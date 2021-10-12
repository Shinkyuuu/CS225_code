#include "Weight.h"

void Weight::setInPounds(const double weightInPounds) {    
    // Pounds to grams conversion.
    weightInGrams = weightInPounds 
                            * POUNDS_TO_OUNCES 
                            * OUNCES_TO_GRAMS;
}