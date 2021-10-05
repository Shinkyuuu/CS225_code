#include "Volume.h"

void Volume::setInGallons(const double volumeInGallons) {
    volumeInCC = volumeInGallons * GALLONS_TO_LITERS * LITERS_TO_CC;
}

