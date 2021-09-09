#pragma once

class Point {
	double x;
	double y;
public:
	void enter();
	double getX() const { return x; }
	double getY() const { return y; }
	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }
	void print() const;
	double getDistanceTo(Point pt2) const;
	double getDistanceTo(const Point* pt2) const;

};

