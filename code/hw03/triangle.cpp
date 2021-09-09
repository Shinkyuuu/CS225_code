#include "Triangle.h"

void Triangle::init() {
	// Ask point for 3 points and add them to a triangle
	vertex1.init();
	vertex2.init(); 
	vertex3.init();
}

void Triangle::print() const {
	vertex1.print();
	vertex2.print();
	vertex3.print();
}

Point Triangle::getCentroid() const {
	Point centroid;
	double centroidX = 0;
	double centroidY = 0;

	centroidX = (vertex1.getX() + vertex2.getX() + vertex3.getX()) / 3.0;
	centroidY = (vertex1.getY() + vertex2.getY() + vertex3.getY()) / 3.0;

	centroid.setX(centroidX);
	centroid.setY(centroidY);

	return centroid;
}

double Triangle::getPerimeter() const {
	double perimeter = 0;

	// Add the distance between each point together
	perimeter += vertex1.distanceFromPoint(&vertex2)
		+ vertex2.distanceFromPoint(&vertex3)
		+ vertex3.distanceFromPoint(&vertex1);

	return perimeter;
}