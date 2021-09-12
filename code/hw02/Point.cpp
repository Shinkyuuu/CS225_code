#include <iostream>
#include <iomanip>
#include <cmath>
#include "Point.h"
using std::cout;
using std::cin;
using std::setprecision;
using std::fixed;
using std::endl;

Point getPointFromUser() {
	Point userPoint;
	double userX = 0;
	double userY = 0;

	// Set errorCheck to true if the 'x' or 'y' inputs are invalid
	cout << "Enter the x and y coordinates separated by a space: ";
	cin >> userX;
	cin.ignore(2, ' ');
	cin >> userY;

	// Ask for inputs agian if either coordinate had an invalid input
	while (cin.fail()) {
		cout << "Try again"
			<< "\nEnter the x and y coordinates separated by a space : ";

		cin.clear();
		cin.ignore(999, '\n');

		cin >> userX;
		cin.ignore(2, ' ');
		cin >> userY;
	}

	userPoint.x = userX;
	userPoint.y = userY;

	return userPoint;
}

void printPoint(const Point* pt) {
	cout << setprecision(2) << fixed
		<< '[' << pt->x << ", " << pt->y << "] ";
}

double distanceBetweenPoints(const Point* pt1, const Point* pt2) {
	// Just distance equation 
	return sqrt(pow(pt1->x - pt2->x, 2) + pow(pt1->y - pt2->y, 2));
}
