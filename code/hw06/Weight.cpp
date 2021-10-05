#include <iostream>
#include "Weight.h"
using namespace std;

void Weight::setInPounds(const double weightInPounds) {    
    weightInGrams = weightInPounds * POUNDS_TO_OUNCES * OUNCES_TO_GRAMS;
}