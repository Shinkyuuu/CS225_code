#include <iostream>
#include <iomanip>
#include <string>
#include "Temperature.h"
using namespace std;

void getTemperatureFromUser(Temperature* userTemp);

int main() {
    Temperature userTemp;
    getTemperatureFromUser(&userTemp);

    cout << setprecision(2) << fixed;
    cout << "That temperature in Celcius is " << userTemp.getCelcius() << "\n";
    cout << "That temperature in Fahrenheit is " << userTemp.getFahrenheit() << "\n";
    cout << "That temperature in Kelvin is " << userTemp.getKelvin() << endl;

    return EXIT_SUCCESS;;
}


void getTemperatureFromUser(Temperature* userTemp) {
    double tempValue;
    string tempUnit;
    // Checks to see if tempUnit corresponds to an acrual temperature unit (Kelvin, Celcius, or Fahrenheit)
    bool tempUnitFail; 

    cout << "Enter a temperature followed by the units: ";
    cin >> tempValue;
    cin.ignore(2, ' ');
    cin >> tempUnit;

    // Check if the temperature units corresponds to actual temperature unit
    tempUnitFail = (tempUnit.compare("F") != 0 &&
               tempUnit.compare("C") != 0 &&
               tempUnit.compare("K") != 0);

    // Error Check
    while (cin.fail() || tempUnitFail) {
        cout << "That input was invalid, try again.\n";
        cout << "Enter a temperature followed by the units: ";
        cin.clear();
        cin.ignore(999, '\n');

        cin >> tempValue;
        cin.ignore(2, ' ');
        cin >> tempUnit;

        tempUnitFail = (tempUnit.compare("F") != 0 &&
            tempUnit.compare("C") != 0 &&
            tempUnit.compare("K") != 0);
    }

    // Convert the inputted temperature into Fahrenheit within the Temperature object.
    if (tempUnit.compare("F") == 0) {
        userTemp->setFahrenheit(tempValue);
    } else if (tempUnit.compare("C") == 0) {
        userTemp->setCelcius(tempValue);
    } else if (tempUnit.compare("K") == 0) {
        userTemp->setKelvin(tempValue);
    }
}