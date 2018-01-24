#pragma once
#include "Point.hpp"

class Circle
{
public:
	Circle();
	Circle(int x, int y, int radius);
	Circle(float x, float y, float radius);
	Circle(double x, double y, double radius);
	Circle(Point center, int radius);
	Circle(Point center, float radius);
	Circle(Point center, double radius);
	~Circle();

	Point Center;
	double Radius;
};