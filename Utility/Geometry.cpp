#include "stdafx.h"
#include "Geometry.hpp"

double Geometry::DistanceBetweenTwoPoints(Point p1, Point p2)
{
	double diffX = abs(p1.X - p2.X);
	double diffY = abs(p1.Y - p2.Y);

	return sqrt((diffX * diffX) + (diffY * diffY));
}

bool Geometry::ContactCircleAndRectangle(Point circleCenter, double radius, Point minRect, Point maxRect)
{
	// Rough check assuming circle is a rectangle (to save on computation power)
	double maxX = circleCenter.X + radius;
	if (maxX > minRect.X) {
		if (maxX < maxRect.X) 
		{
			double maxY = circleCenter.Y + radius;
			if (maxY > minRect.Y) {
				if (maxY < maxRect.Y) 
				{
					// Getting to this point, circle contact will only fail on the corners of the rectangle
					if (DistanceBetweenTwoPoints(circleCenter, minRect) < radius) return true;
					if (DistanceBetweenTwoPoints(circleCenter, maxRect) < radius) return true;
					if (DistanceBetweenTwoPoints(circleCenter, Point(minRect.X, maxRect.Y)) < radius) return true;
					if (DistanceBetweenTwoPoints(circleCenter, Point(maxRect.X, minRect.Y)) < radius) return true;
				}
			}
		}
	}
	return false;
}

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
	if (r1.MinPt.X < r2.MaxPt.X) {
		if (r1.MaxPt.X > r2.MinPt.X) {
			if (r1.MinPt.Y < r2.MaxPt.Y) {
				if (r1.MaxPt.Y > r2.MinPt.Y) {
					return true;
				}
			}
		}
	}
	return false;
}