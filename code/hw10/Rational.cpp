#include <iostream>
#include "Rational.h"
using std::ostream;

static int getGCD(int a, int b) {
    while (a != b) {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

// simplify to lowest terms with positive denominator 
void Rational::normalize() {
    // zero is a special case 
    if (numerator == 0) {
        denominator = 1;
    }
    else {
        // divide out the greatest common divisor 
        int gcd = getGCD(numerator, denominator);
        if (gcd > 1) {
            numerator /= gcd;
            denominator /= gcd;
        }
        // make the denominator positive 
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }
}

Rational Rational::operator* (const Rational& other) {
    Rational solu;
    solu.numerator = this->numerator * other.numerator;
    solu.denominator = this->denominator * other.denominator;

    solu.normalize();
    return solu;
}

Rational Rational::operator/ (const Rational& other) {
    Rational solu;
    solu.numerator = this->numerator * other.denominator;
    solu.denominator = this->denominator * other.numerator;

    solu.normalize();
    return solu;
}

Rational Rational::operator+ (const Rational& other) {
    Rational solu;
    solu.numerator = (this->numerator * other.denominator) + 
                                 (other.numerator * this->denominator);
    solu.denominator = this->denominator * other.denominator;

    solu.normalize();
    return solu;
}

Rational Rational::operator- (const Rational& other) {
    Rational solu;
    solu.numerator = (this->numerator * other.denominator) -
                                 (other.numerator * this->denominator);
    solu.denominator = this->denominator * other.denominator;

    solu.normalize();
    return solu;
}

Rational Rational::operator= (const Rational& other) {
    this->numerator = other.numerator;
    this->denominator = other.denominator;

    return *this;
}

bool Rational::operator== (const Rational& other) const {
    return (this->numerator == other.numerator &&
                this->denominator == other.denominator);
}

bool Rational::operator!= (const Rational& other) const {
    return !(*this == other);
}

Rational::operator double() const {
    return double(numerator) / double(denominator);
}

ostream& operator <<(ostream& os, const Rational& other) {
    os << "(" << other.numerator << "/" << other.denominator << ")";

    return os;
}