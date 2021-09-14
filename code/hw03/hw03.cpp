#include <iostream>
#include <iomanip>
#include "Triangle.h"
#include "Point.h"
using std::cout;
using std::setprecision;
using std::fixed;
using std::endl;

int main() {
	Triangle userTriangle;

	userTriangle.enter();

	cout << "The triangle vertices are ";
	userTriangle.print();

	cout << "\nThe centroid is ";
	userTriangle.getCentroid().print();

	cout << setprecision(2) << fixed
		<< "\nThe perimeter is " << userTriangle.getPerimeter() << endl;
	
	return 0;
}

