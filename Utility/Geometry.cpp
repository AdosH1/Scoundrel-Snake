#include "stdafx.h"
#include "Geometry.hpp"

double Geometry::DistanceBetweenTwoPoints(Point p1, Point p2)
{
	double diffX = abs(p1.X - p2.X);
	double diffY = abs(p1.Y - p2.Y);

	return sqrt((diffX * diffX) + (diffY * diffY));
}

Point Geometry::RandomPointWithinRectangle(Rectangle rect)
{
	double x = rand() % (int)rect.Max.X + (int)rect.Min.X;
	double y = rand() % (int)rect.Max.Y + (int)rect.Min.Y;
	return Point(x, y);
}

Point Geometry::RandomPointWithinRectangle(Point min, Point max)
{
	double x = rand() % (int)max.X + (int)min.X;
	double y = rand() % (int)max.Y + (int)min.Y;
	return Point(x, y);
}

Point Geometry::RandomPointWithinRectangleAwayFromPoint(Rectangle rect, Point awayFrom, double distanceXY)
{
	distanceXY = abs(distanceXY);
	double x;
	double y;
	rect.Max.X -= rect.Min.X;
	rect.Max.Y -= rect.Min.Y;
	/*if (rect.Min.X < 0) rect.Max.X -= rect.Min.X;
	if (rect.Min.Y < 0) rect.Max.Y -= rect.Min.Y;*/
	do
	{
		x = rand() % (int)rect.Max.X + (int)rect.Min.X;
		y = rand() % (int)rect.Max.Y + (int)rect.Min.Y;
	} while (abs(awayFrom.X - x) < distanceXY || abs(awayFrom.Y - y) < distanceXY);
	
	return Point(x, y);
}

Point Geometry::RandomPointWithinRectangleAwayFromListOfPoints(Rectangle rect, std::deque<Point> listOfPoints, double distanceXY)
{
	distanceXY = abs(distanceXY);
	double x;
	double y;
	rect.Max.X -= rect.Min.X;
	rect.Max.Y -= rect.Min.Y;
	int length = listOfPoints.size();
	bool found = false;
	bool fail = false;

	while (!found)
	{
		fail = false;
		x = rand() % (int)rect.Max.X + (int)rect.Min.X;
		y = rand() % (int)rect.Max.Y + (int)rect.Min.Y;

		for (int i = 0; i < length; i++)
		{
			Point p = listOfPoints.at(i);
			if (abs(p.X - x) > distanceXY || abs(p.Y - y) > distanceXY) continue;
			fail = true;
		}
		if (!fail) found = true;
	}
	return Point(x, y);
}

Point Geometry::PointDifference(Point p1, Point p2)
{
	Point p3 = p1 - p2;
	p3.X = abs(p3.X);
	p3.Y = abs(p3.Y);

	return p3;
}

#pragma region Circle And Circle
bool Geometry::ContactCircleAndCircle(Point c1, double r1, Point c2, double r2)
{
	if (ContactRectangleAndRectangle(Point(c1.X - r1, c1.Y - r1), Point(c1.X + r1, c1.Y + r1), Point(c2.X - r2, c2.Y - r2), Point(c2.X + r2, c2.Y + r2)))
		return true;
	else
		return (DistanceBetweenTwoPoints(c1, c2) < r1 + r2);
}

bool Geometry::ContactCircleAndCircle(Circle c1, Circle c2)
{
	if (ContactRectangleAndRectangle(Rectangle(Point(c1.Center.X - c1.Radius, c1.Center.Y - c1.Radius), Point(c1.Center.X + c1.Radius, c1.Center.Y + c1.Radius)), Rectangle(Point(c2.Center.X - c2.Radius, c2.Center.Y - c2.Radius), Point(c2.Center.X + c2.Radius, c2.Center.Y + c2.Radius))))
		return true;
	else
		return (DistanceBetweenTwoPoints(c1.Center, c2.Center) < c1.Radius + c2.Radius);
}
#pragma endregion

#pragma region Circle And Rectangle
bool Geometry::ContactCircleAndRectangle(Point circleCenter, double radius, Point minRect, Point maxRect)
{
	// If speed is needed, take apart this object
	Rectangle rect = Rectangle(minRect, maxRect);
	double distX = abs(circleCenter.X - rect.Center.X);
	double distY = abs(circleCenter.Y - rect.Center.Y);
	double halfHeight = rect.Height / 2;
	double halfWidth = rect.Width / 2;

	if (distX > halfWidth + radius) return false;
	if (distY > halfHeight + radius) return false;

	if (distX <= halfWidth) return true;
	if (distY <= halfHeight) return true;

	double distCorner = pow((distX - halfWidth), 2) + pow(distY - halfHeight, 2);
	return distCorner < pow(radius, 2);
}

bool Geometry::ContactCircleAndRectangle(Point circleCenter, double radius, Rectangle rect)
{
	double distX = abs(circleCenter.X - rect.Center.X);
	double distY = abs(circleCenter.Y - rect.Center.Y);
	double halfHeight = rect.Height / 2;
	double halfWidth = rect.Width / 2;

	if (distX > halfWidth + radius) return false;
	if (distY > halfHeight + radius) return false;

	if (distX <= halfWidth) return true;
	if (distY <= halfHeight) return true;

	double distCorner = pow((distX - halfWidth), 2) + pow(distY - halfHeight,2);
	return distCorner < pow(radius, 2);
}

bool Geometry::ContactCircleAndRectangle(Circle circle, Point minRect, Point maxRect)
{
	// If speed is needed, take apart this object
	Rectangle rect = Rectangle(minRect, maxRect);
	double distX = abs(circle.Center.X - rect.Center.X);
	double distY = abs(circle.Center.Y - rect.Center.Y);
	double halfHeight = rect.Height / 2;
	double halfWidth = rect.Width / 2;

	if (distX > halfWidth + circle.Radius) return false;
	if (distY > halfHeight + circle.Radius) return false;

	if (distX <= halfWidth) return true;
	if (distY <= halfHeight) return true;

	double distCorner = pow((distX - halfWidth), 2) + pow(distY - halfHeight, 2);
	return distCorner < pow(circle.Radius, 2);
}

bool Geometry::ContactCircleAndRectangle(Circle circle, Rectangle rect)
{
	double distX = abs(circle.Center.X - rect.Center.X);
	double distY = abs(circle.Center.Y - rect.Center.Y);
	double halfHeight = rect.Height / 2;
	double halfWidth = rect.Width / 2;

	if (distX > halfWidth + circle.Radius) return false;
	if (distY > halfHeight + circle.Radius) return false;

	if (distX <= halfWidth) return true;
	if (distY <= halfHeight) return true;

	double distCorner = pow((distX - halfWidth), 2) + pow(distY - halfHeight, 2);
	return distCorner < pow(circle.Radius, 2);
}
#pragma endregion 

#pragma region Rectangle And Rectangle
// This is an implementation of Axis Aligned Bounding Box (AABB) collision
// as seen in https://www.youtube.com/watch?v=1oNsZCqQDeE
bool Geometry::ContactRectangleAndRectangle(Point minRect1, Point maxRect1, Point minRect2, Point maxRect2)
{
	if (minRect1.X < maxRect2.X) {
		if (maxRect1.X > minRect2.X) {
			if (minRect1.Y < maxRect2.Y) {
				if (maxRect1.Y > minRect2.Y) { 
					return true;
				}
			}
		}
	}
	return false;
}

bool Geometry::ContactRectangleAndRectangle(Rectangle r1, Rectangle r2)
{
	if (r1.Min.X < r2.Max.X) {
		if (r1.Max.X > r2.Min.X) {
			if (r1.Min.Y < r2.Max.Y) {
				if (r1.Max.Y > r2.Min.Y) {
					return true;
				}
			}
		}
	}
	return false;
}
#pragma endregion 

Point Geometry::SetCircleToRectangle(Circle circle, Rectangle rect, bool leaveGap)
{
	if (leaveGap) circle.Radius = circle.Radius * 1.05;
	if (circle.Center.X + circle.Radius < rect.Min.X) circle.Center.X = rect.Min.X - circle.Radius;
	if (circle.Center.Y + circle.Radius < rect.Min.Y) circle.Center.Y = rect.Min.Y - circle.Radius;
	if (circle.Center.X - circle.Radius > rect.Max.X) circle.Center.X = rect.Max.X + circle.Radius;
	if (circle.Center.Y - circle.Radius > rect.Max.Y) circle.Center.Y = rect.Max.Y + circle.Radius;

	return circle.Center;
}
