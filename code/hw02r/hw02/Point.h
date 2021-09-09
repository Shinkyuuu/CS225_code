#pragma once
using std::string;

struct Point {
	double x;
	double y;
};

void printPoint(Point pt);
double distanceBetweenPoints(const Point* pt1, const Point* pt2);
string printablePoint(const Point* pt);
Point getPointFromUser();