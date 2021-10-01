#pragma once
class Temperature {
    double tempF; // Temperature in Fahrenheit
public:
    Temperature();
    void setTemperatureAsFahrenheit(double tempF);
    void setTemperatureAsCelsius(double tempC);
    void setTemperatureAsKelvin(double tempK);
    double getTemperatureAsFahrenheit() const;
    double getTemperatureAsCelcius() const;
    double getTemperatureAsKelvin() const;
};

