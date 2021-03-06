#pragma once
#include "Point.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include <cmath>
#include <deque>

class Geometry
{
public:
	static double DistanceBetweenTwoPoints(Point p1, Point p2);

	static Point RandomPointWithinRectangle(Rectangle rect);
	static Point RandomPointWithinRectangle(Point min, Point max);
	static Point RandomPointWithinRectangleAwayFromPoint(Rectangle rect, Point awayFrom, double distanceXY);
	static Point RandomPointWithinRectangleAwayFromListOfPoints(Rectangle rect, std::deque<Point> listOfPoints, double distanceXY);

	// Returns a point that is the difference between the two provided (p1 - p2) - always positive
	static Point PointDifference(Point p1, Point p2);

	static bool ContactCircleAndCircle(Point c1, double r1, Point c2, double r2);
	static bool ContactCircleAndCircle(Circle c1, Circle c2);

	static bool ContactCircleAndRectangle(Point circleCenter, double radius, Point minRect, Point maxRect);
	static bool ContactCircleAndRectangle(Point circleCenter, double radius, Rectangle rect);
	static bool ContactCircleAndRectangle(Circle circle, Point minRect, Point maxRect);
	static bool ContactCircleAndRectangle(Circle circle, Rectangle rect);

	static bool ContactRectangleAndRectangle(Point minRect1, Point maxRect1, Point minRect2, Point maxRect2);
	static bool ContactRectangleAndRectangle(Rectangle r1, Rectangle r2);

	// Returns a point on where the circle center should be to contact the rectangle (closest distance)
	static Point SetCircleToRectangle(Circle circle, Rectangle rect, bool leaveGap = false);
};