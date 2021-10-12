#include <iostream>
#include "Treasure.h"
using namespace std;

void testTreasure();

int main() {
    testTreasure();
}

// Ask for weight and volume of treasure then tell user if it's pure.
void testTreasure() {
    Treasure newTreasure;
    double weightInPounds;
    double volumeInGallons;

    cout << "Enter the weight (Pounds) and "
            << "volume (Gallons) separated by a space: ";

    cin >> weightInPounds;
    cin.ignore(2, ' ');
    cin >> volumeInGallons;

    // Error check user input (Make sure the inputs are numbers).
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

    newTreasure.setWeight(weightInPounds);
    newTreasure.setVolume(volumeInGallons);

    // Tell user if treasure's density is within 1% of pure gold's density.
    if (newTreasure.isPure(Treasure::GOLD, Treasure::ONE_PERCENT)) {
        cout << "This treasure is pure." << endl;
    } else {
        cout << "This treasure is not pure." << endl;
    }
}
