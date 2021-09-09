#pragma once
#include "Point.h"

struct Triangle {
	Point vertex1;
	Point vertex2;
	Point vertex3;
};

Triangle getTriangleFromUser();
void printVertices(const Triangle* ptrThis);
Point getCentroid(const Triangle* ptrThis);
double getPerimeter(const Triangle* ptrThis);