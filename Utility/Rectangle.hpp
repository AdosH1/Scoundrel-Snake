#pragma once
#include "Point.hpp"

class Rectangle
{
public:
	Rectangle();
	Rectangle(int x1, int y1, int x2, int y2);
	Rectangle(float x1, float y1, float x2, float y2);
	Rectangle(double x1, double y1, double x2, double y2);
	Rectangle(Point minPt, Point maxPt);
	~Rectangle();

	Point MinPt;
	Point MaxPt;
};