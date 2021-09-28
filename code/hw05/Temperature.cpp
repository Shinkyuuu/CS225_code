#include <iostream>
#include "Temperature.h"

Temperature::Temperature() {
    tempF = 0.0;
}

void Temperature::setFahrenheit(double tempF) {
    this->tempF = tempF;
}

void Temperature::setCelcius(double tempC) {
    // Celcius to Fahrenheit conversion
    tempF = (tempC * (9.0 / 5.0)) + 32.0;
}

void Temperature::setKelvin(double tempK) {
    // Kelvin to Fahrenheit conversion
    tempF = (tempK - 273.15) * (9.0 / 5.0) + 32.0;
}

double Temperature::getFahrenheit() const {
    return tempF;
}

double Temperature::getCelcius() const {
    // Fahrenheit to Celcius conversion
    return (tempF - 32.0) * (5.0 / 9.0); 
}

double Temperature::getKelvin() const {
    // Fahrenheit to Kelvin conversion
    return (tempF - 32.0) * (5.0 / 9.0) + 273.15;
}