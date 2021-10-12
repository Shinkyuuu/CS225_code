#include "Volume.h"

void Volume::setInGallons(const double volumeInGallons) {
    // Gallons to cubic centimers conversion.
    volumeInCC = volumeInGallons 
                        * GALLONS_TO_LITERS    
                        * LITERS_TO_CC;
}

