#pragma once

class Point {
	double x;
	double y;
public:
	void init();
	void setX(double x);
	void setY(double y);
	double getX() const;
	double getY() const;
	void print() const;
	double distanceFromPoint(const Point* pt2) const;
};

