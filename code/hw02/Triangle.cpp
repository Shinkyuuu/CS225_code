#include "Triangle.h"

Triangle getTriangleFromUser() {
	Triangle userTriangle;

	// Ask user for 3 points and add them to a triangle
	userTriangle.vertex1 = getPointFromUser();
	userTriangle.vertex2 = getPointFromUser();
	userTriangle.vertex3 = getPointFromUser();

	return userTriangle;
}

void printVertices(const Triangle* ptrThis) {
	printPoint(&(ptrThis->vertex1));
	printPoint(&(ptrThis->vertex2));
	printPoint(&(ptrThis->vertex3));
}

Point getCentroid(const Triangle* ptrThis) {
	Point centroid;

	// Centroid equation
	centroid.x = (ptrThis->vertex1.x 
		+ ptrThis->vertex2.x 
		+ ptrThis->vertex3.x) / 3.0;
	centroid.y = (ptrThis->vertex1.y 
		+ ptrThis->vertex2.y 
		+ ptrThis->vertex3.y) / 3.0;

	return centroid;
}

double getPerimeter(const Triangle* ptrThis) {
	double perimeter = 0;

	// Add the distance between each point together
	perimeter += 
		distanceBetweenPoints(&(ptrThis->vertex1), &(ptrThis->vertex2))
		+ distanceBetweenPoints(&(ptrThis->vertex2), &(ptrThis->vertex3))
		+ distanceBetweenPoints(&(ptrThis->vertex3), &(ptrThis->vertex1));

	return perimeter;
}