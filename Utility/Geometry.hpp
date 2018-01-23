#pragma once
#include "Point.hpp"
#include "Rectangle.hpp"
#include <cmath>

class Geometry
{
public:
	double DistanceBetweenTwoPoints(Point p1, Point p2);

	bool ContactCircleAndRectangle(Point circleCenter, double radius, Point minRect, Point maxRect);


	bool ContactRectangleAndRectangle(Point minRect1, Point maxRect1, Point minRect2, Point maxRect2);
	bool ContactRectangleAndRectangle(Rectangle r1, Rectangle r2);
};