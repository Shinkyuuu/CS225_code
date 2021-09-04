#include <iostream>
using namespace std;

typedef struct Point {
	double x;
	double y;
} Point;

typedef struct Triangle {
	Point vertex1;
	Point vertex2;
	Point vertex3;
} Triangle;

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

int main() {
	Triangle triangle;

	triangle.vertex1 = getPointFromUser();
	triangle.vertex2 = getPointFromUser();
	triangle.vertex3 = getPointFromUser();

	return 0;
}