#include "Temperature.h"

Temperature::Temperature() {
    tempF = 0;
}

void Temperature::setTemperatureAsFahrenheit(double tempF) {
    this->tempF = tempF;
}

void Temperature::setTemperatureAsCelsius(double tempC) {
    // Celcius to Fahrenheit conversion
    tempF = (tempC * 9.0 / 5.0) + 32.0;
}

void Temperature::setTemperatureAsKelvin(double tempK) {
    // Kelvin to Fahrenheit conversion
    tempF = (tempK - 273.15) * (9.0 / 5.0) + 32.0;
}

double Temperature::getTemperatureAsFahrenheit() const {
    return tempF;
}

double Temperature::getTemperatureAsCelcius() const {
    // Fahrenheit to Celcius conversion
    return (tempF - 32.0) * (5.0 / 9.0); 
}

double Temperature::getTemperatureAsKelvin() const {
    // Fahrenheit to Kelvin conversion
    return ((tempF - 32.0) * 5.0 / 9.0) + 273.15;
}