#include <iostream>
#include <iomanip>
#include <cmath>
#include "Point.h"
using std::cout;
using std::cin;
using std::setprecision;
using std::fixed;
using std::endl;

void Point::init() {
	// Set errorCheck to true if the 'x' or 'y' inputs are invalid
	cout << "Enter the x and y coordinates separated by a space: ";
	cin >> x;
	cin.ignore(2, ' ');
	cin >> y;

	// Ask for inputs agian if either coordinate had an invalid input
	while (cin.fail()) {
		cout << "Try again \nEnter the x and y coordinates separated by a space: ";

		cin.clear();
		cin.ignore(999, '\n');

		cin >> x;
		cin.ignore(2, ' ');
		cin >> y;
	}

	cin.clear();
	cin.ignore(999, '\n');
}

double Point::getX() const { return x; }
double Point::getY() const { return y; }

void Point::setX(double x) { this->x = x; }
void Point::setY(double y) { this->y = y; }

void Point::print() const {
	cout << setprecision(2) << fixed
		<< '[' << x << ", " <<  y << "] ";
}

double Point::distanceFromPoint(const Point* pt2) const {
	// Just distance equation 
	return sqrt(pow(this->x - pt2->x, 2) + pow(this->y - pt2->y, 2));
}