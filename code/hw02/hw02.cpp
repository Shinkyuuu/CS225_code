#include <iostream>
#include <iomanip>
#include "Triangle.h"
#include "Point.h"
using std::cout;
using std::setprecision;
using std::fixed;
using std::endl;

int main() {
	Triangle triangle;
	Point centroid;
	double perimeter;

	triangle = getTriangleFromUser();
	centroid = getCentroid(&triangle);
	perimeter = getPerimeter(&triangle);

	cout << "The triangle vertices are ";
	printVertices(&triangle);

	cout << "\nThe centroid is ";
	printPoint(&centroid);

	cout << setprecision(2) << fixed
		<< "\nThe perimeter is " << perimeter << endl;

	return 0;
}




