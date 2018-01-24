#include "stdafx.h"
#include "Circle.hpp"

Circle::Circle()
{
	Center = Point();
	Radius = 1;
}

Circle::Circle(int x, int y, int radius)
{
	Center = Point(x, y);
	Radius = radius;
}

Circle::Circle(float x, float y, float radius)
{
	Center = Point(x, y);
	Radius = radius;
}

Circle::Circle(double x, double y, double radius)
{
	Center = Point(x, y);
	Radius = radius;
}

Circle::Circle(Point center, int radius)
{
	Center = center;
	Radius = radius;
}

Circle::Circle(Point center, float radius)
{
	Center = center;
	Radius = radius;
}

Circle::Circle(Point center, double radius)
{
	Center = center;
	Radius = radius;
}

Circle::~Circle() = default;