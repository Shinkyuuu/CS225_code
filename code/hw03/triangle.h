#pragma once
#include "Point.h"

class Triangle {
	Point vertex1;
	Point vertex2;
	Point vertex3;
public:
	void enter();
	void print() const;
	Point getCentroid() const;
	double getPerimeter() const;
};

