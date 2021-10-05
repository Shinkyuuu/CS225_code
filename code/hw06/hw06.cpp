#include <iostream>
#include "Treasure.h"
using namespace std;

void testTreasure();

int main() {
    testTreasure();
}

void testTreasure() {
    Weight treasureWeight;
    Volume treasureVolume;
    double weightInPounds;
    double volumeInGallons;

    cout << "Enter the weight (Pounds) and "
            << "volume (Gallons) separated by a space: ";
    cin >> weightInPounds;
    cin.ignore(2, ' ');
    cin >> volumeInGallons;

    while (cin.fail()) {
        cout << "There was an error, try again.\n";
        cout << "Enter the weight (Pounds) and "
            << "volume (Gallons) separated by a space: ";

        cin.clear();
        cin.ignore(999, '\n');

        cin >> weightInPounds;
        cin.ignore(2, ' ');
        cin >> volumeInGallons;
    }

    treasureWeight.setInPounds(weightInPounds);
    treasureVolume.setInGallons(volumeInGallons);

    Treasure newTreasure;
    newTreasure.setWeight(weightInPounds);
    newTreasure.setVolume(volumeInGallons);

    if (newTreasure.isPure(Treasure::GOLD, Treasure::ONE_PERCENT)) {
        cout << "This is pure." << endl;
    } else {
        cout << "This is pure." << endl;
    }
}
