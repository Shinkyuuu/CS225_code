#pragma once

struct Point {
	double x;
	double y;
};

Point getPointFromUser();
void printPoint(const Point* pt);
double distanceBetweenPoints(const Point* pt1, const Point* pt2);
