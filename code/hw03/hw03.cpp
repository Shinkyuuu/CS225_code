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

	triangle.init();

	cout << "The triangle vertices are ";
	triangle.print();
	cout << "\nThe centroid is ";
	triangle.getCentroid().print();
	cout << setprecision(2) << fixed
		<< "\nThe perimeter is " << triangle.getPerimeter() << endl;
	
	return 0;
}

