#pragma once
class Temperature {
    double tempF; // Temperature in Fahrenheit
public:
    Temperature();
    void setFahrenheit(double tempF);
    void setCelcius(double tempC);
    void setKelvin(double tempK);
    double getFahrenheit() const;
    double getCelcius() const;
    double getKelvin() const;
};

