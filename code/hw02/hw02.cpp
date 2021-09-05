#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include "Triangle.h"
#include "Point.h"
using namespace std;

string printablePoint(const Point* pt) {
	stringstream ss;

	ss << setprecision(2) << fixed 
        << '[' 
        << pt->x << ", " << pt->y 
        << ']';

	return ss.str();
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
		cout << "Try again \n";
        cout << "Enter the x and y coordinates separated by a space: ";

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

double distanceBetweenPoints(const Point* pt1, const Point* pt2) {
	return sqrt(pow(pt1->x - pt2->x, 2) + pow(pt1->y - pt2->y, 2));
}

void printPoint(Point pt) {
	cout << printablePoint(&pt) << " ";
}

Triangle getTriangleFromUser() {
	Triangle triangle;

	triangle.vertex1 = getPointFromUser();
	triangle.vertex2 = getPointFromUser();
	triangle.vertex3 = getPointFromUser();

	return triangle;
}

void printVertices(const Triangle *ptrThis) {
    printPoint(ptrThis->vertex1);
    printPoint(ptrThis->vertex2);
    printPoint(ptrThis->vertex3);
}

Point getCentroid(const Triangle *ptrThis) {
    Point centroid;

    centroid.x = (ptrThis->vertex1.x + ptrThis->vertex2.x + ptrThis->vertex3.x) / 3.0;
    centroid.y = (ptrThis->vertex1.y + ptrThis->vertex2.y + ptrThis->vertex3.y) / 3.0;

    return centroid;
}

double getPerimeter(const Triangle *ptrThis) {
    double perimeter = 0;

    perimeter += distanceBetweenPoints(&(ptrThis->vertex1), &(ptrThis->vertex2))
        + distanceBetweenPoints(&(ptrThis->vertex2), &(ptrThis->vertex3))
        + distanceBetweenPoints(&(ptrThis->vertex3), &(ptrThis->vertex1));

        return perimeter;
} 

int main() {
    Triangle triangle;

    triangle = getTriangleFromUser();
    cout << "The triangle vertices are ";
    printVertices(&triangle);
    cout << "\nThe centroid is ";
    printPoint(getCentroid(&triangle));
    cout << setprecision(2) << fixed 
        << "\nThe perimeter is " 
        << getPerimeter(&triangle) 
        << endl;

	return 0;
}