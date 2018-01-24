#include "stdafx.h"
#include "Rectangle.hpp"

Rectangle::Rectangle()
{
	Min = Point(0, 0);
	Max = Point(1, 1);
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2)
{
	
	Min.X = fmin(x1, x2);
	Min.Y = fmin(y1, y2);
	Max.X = fmax(x1, x2);
	Max.Y = fmax(y1, y2);
}

Rectangle::Rectangle(float x1, float y1, float x2, float y2)
{
	Min.X = fmin(x1, x2);
	Min.Y = fmin(y1, y2);
	Max.X = fmax(x1, x2);
	Max.Y = fmax(y1, y2);
}

Rectangle::Rectangle(double x1, double y1, double x2, double y2)
{
	Min.X = fmin(x1, x2);
	Min.Y = fmin(y1, y2);
	Max.X = fmax(x1, x2);
	Max.Y = fmax(y1, y2);
}

Rectangle::Rectangle(Point p1, Point p2)
{
	Min.X = fmin(p1.X, p2.X);
	Min.Y = fmin(p1.Y, p2.Y);
	Max.X = fmax(p1.X, p2.X);
	Max.Y = fmax(p1.Y, p2.Y);
}

Rectangle::~Rectangle() = default;