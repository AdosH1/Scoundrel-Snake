#pragma once
#include "Point.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include <cmath>

class Geometry
{
public:
	static double DistanceBetweenTwoPoints(Point p1, Point p2);

	static bool ContactCircleAndRectangle(Point circleCenter, double radius, Point minRect, Point maxRect);
	static bool ContactCircleAndRectangle(Circle circle, Point minRect, Point maxRect);
	static bool ContactCircleAndRectangle(Circle circle, Rectangle rect);

	static bool ContactRectangleAndRectangle(Point minRect1, Point maxRect1, Point minRect2, Point maxRect2);
	static bool ContactRectangleAndRectangle(Rectangle r1, Rectangle r2);
};