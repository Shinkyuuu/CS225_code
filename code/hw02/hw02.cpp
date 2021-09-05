#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include "Triangle.h"
#include "Point.h"
using namespace std;

string printablePoint(const Point* pt) {
	stringstream ss;

	ss << setprecision(2) << fixed << '[' << pt->x << ", " << pt->y << ']';
	return ss.str();
}

void printPoint(Point pt) {
	cout << printablePoint(&pt);
}

Point getPointFromUser() {
	bool errorCheck = false;
	Point userPoint;
	double userX = 0;
	double userY = 0;

	cout << "Enter the x and y coordinates separated by a space: ";
	cin >> userX;
	if (cin.fail()) {errorCheck = true;}

	cin >> userY;
	if (cin.fail()) {errorCheck = true;}

	while (errorCheck) {
		errorCheck = false;
		cout << "Wrong input try again: ";
		cin.clear();
		cin.ignore(999, '\n');

		cin >> userX;
		if (cin.fail()) errorCheck = true;

		cin >> userY;
		if (cin.fail()) errorCheck = true;
	}

	userPoint.x = userX;
	userPoint.y = userY;

	return userPoint;
}

Triangle getTriangleFromUser() {
	Triangle triangle;

	triangle.vertex1 = getPointFromUser();
	triangle.vertex2 = getPointFromUser();
	triangle.vertex3 = getPointFromUser();

	return triangle;
}

double distanceBetweenPoints(const Point* vertex1, const Point* vertex2) {
	return sqrt(pow(vertex1->x - vertex2->x, 2) + pow(vertex1->y - vertex2->y, 2));
}

int main() {

	return 0;
}