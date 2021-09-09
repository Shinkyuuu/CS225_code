#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include "Point.h"
using namespace std;


//Convert point into printable string
string printablePoint(const Point* pt) {
	stringstream ss;

	ss << setprecision(2) << fixed
		<< '['
		<< pt->x << ", " << pt->y
		<< ']';

	return ss.str();
}

Point getPointFromUser() {
	Point userPoint;
	double userX = 0;
	double userY = 0;

	// Set errorCheck to true if the 'x' or 'y' inputs are invalid
	cout << "Enter the x and y coordinates separated by a space: ";
	cin >> userX;
	cin >> userY; 
	cin.ignore(2, ' ');

	// Ask for inputs agian if either coordinate had an invalid input
	while (cin.fail()) {
		cout << "Try again \n";
		cout << "Enter the x and y coordinates separated by a space: ";

		cin.clear();
		cin.ignore(999, '\n');

		cin >> userX;
		cin >> userY;
		cin.ignore(2, ' ');
	}

	userPoint.x = userX;
	userPoint.y = userY;

	return userPoint;
}

double distanceBetweenPoints(const Point* pt1, const Point* pt2) {
	// Just distance equation 
	return sqrt(pow(pt1->x - pt2->x, 2) + pow(pt1->y - pt2->y, 2));
}

void printPoint(Point pt) {
	cout << printablePoint(&pt) << " ";
}