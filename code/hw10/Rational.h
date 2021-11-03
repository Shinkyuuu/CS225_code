#pragma once
#include <iostream>

class Rational {
    int numerator;
    int denominator;
    void normalize();
public:
    Rational() : Rational(0, 1) {}

    Rational(int numerator, int denominator) :
        numerator(numerator), denominator(denominator)
    {
        normalize();
    }

    Rational operator* (const Rational& other);
    Rational operator/ (const Rational& other);
    Rational operator+ (const Rational& other);
    Rational operator- (const Rational& other);
    Rational operator= (const Rational& other);
    bool operator== (const Rational& other) const;
    bool operator!= (const Rational& other) const;

    operator double() const;
    friend std::ostream& operator<< (std::ostream& os, const Rational& other);
};

