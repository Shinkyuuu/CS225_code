#include <iostream>
#include <iomanip>
#include <cmath>
#include "Point.h"
using std::cout;
using std::cin;
using std::setprecision;
using std::fixed;
using std::endl;

void Point::enter() {
	cout << "Enter the x and y coordinates separated by a space: ";
	cin >> x;
	cin.ignore(2, ' ');
	cin >> y;

	// Ask for inputs again if either coordinate had an invalid input
	while (cin.fail()) {
		cout << "Try again" 
			<< "\nEnter the x and y coordinates separated by a space : ";

		cin.clear();
		cin.ignore(999, '\n');

		cin >> x;
		cin.ignore(2, ' ');
		cin >> y;
	}

	cin.clear();
	cin.ignore(999, '\n');
}

void Point::print() const {
	cout << setprecision(2) << fixed
		<< '[' << x << ", " <<  y << "] ";
}

double Point::getDistanceTo(const Point pt2) const {
	// Just distance equation 
	return sqrt(pow(x - pt2.x, 2) + pow(y - pt2.y, 2));
}

double Point::getDistanceTo(const Point* pt2) const {
	// Just distance equation 
	return sqrt(pow(x - pt2->x, 2) + pow(y - pt2->y, 2));
}