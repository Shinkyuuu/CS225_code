#include <iostream>
#include <iomanip>
#include "Triangle.h"
#include "Point.h"
using namespace std;

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




