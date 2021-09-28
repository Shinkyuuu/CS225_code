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

    return 0;
}

void getTemperatureFromUser(Temperature* userTemp) {
    double tempValue;
    string tempUnit;
    bool tempUnitFail = false;

    cout << "Enter a temperature followed by the units: ";
    cin >> tempValue;
    cin.ignore(2, ' ');
    cin >> tempUnit;

    tempUnitFail = (tempUnit.compare("F") != 0 &&
               tempUnit.compare("C") != 0 &&
               tempUnit.compare("K") != 0);

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

    if (tempUnit.compare("F") == 0) {
        userTemp->setFahrenheit(tempValue);
    } else if (tempUnit.compare("C") == 0) {
        userTemp->setCelcius(tempValue);
    } else if (tempUnit.compare("K") == 0) {
        userTemp->setKelvin(tempValue);
    }
}