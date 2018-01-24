#include "stdafx.h"
#include "Rectangle.hpp"

Rectangle::Rectangle()
{
	MinPt = Point(0, 0);
	MaxPt = Point(1, 1);
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2)
{
	
	MinPt.X = fmin(x1, x2);
	MinPt.Y = fmin(y1, y2);
	MaxPt.X = fmax(x1, x2);
	MaxPt.Y = fmax(y1, y2);
}

Rectangle::Rectangle(float x1, float y1, float x2, float y2)
{
	MinPt.X = fmin(x1, x2);
	MinPt.Y = fmin(y1, y2);
	MaxPt.X = fmax(x1, x2);
	MaxPt.Y = fmax(y1, y2);
}

Rectangle::Rectangle(double x1, double y1, double x2, double y2)
{
	MinPt.X = fmin(x1, x2);
	MinPt.Y = fmin(y1, y2);
	MaxPt.X = fmax(x1, x2);
	MaxPt.Y = fmax(y1, y2);
}

Rectangle::Rectangle(Point p1, Point p2)
{
	MinPt.X = fmin(p1.X, p2.X);
	MinPt.Y = fmin(p1.Y, p2.Y);
	MaxPt.X = fmax(p1.X, p2.X);
	MaxPt.Y = fmax(p1.Y, p2.Y);
}

Rectangle::~Rectangle() = default;