#include "stdafx.h"
#include "Point.hpp"

Point::Point()
{
	X = 0;
	Y = 0;
}

Point::~Point()
{

}

Point::Point(int x, int y)
{
	X = x;
	Y = y;
}

Point::Point(float x, float y)
{
	X = x;
	Y = y;
}

Point::Point(double x, double y)
{
	X = x;
	Y = y;
}

Point Point::operator*(const int& multiplier)
{
	Point pt;
	pt.X = X * multiplier;
	pt.Y = Y * multiplier;

	return pt;
}

Point Point::operator*(const float& multiplier)
{
	Point pt;
	pt.X = X * multiplier;
	pt.Y = Y * multiplier;

	return pt;
}

Point Point::operator*(const double& multiplier)
{
	Point pt;
	pt.X = X * multiplier;
	pt.Y = Y * multiplier;

	return pt;
}

Point Point::operator+(const Point& p)
{
	Point pt;
	pt.X = this->X + p.X;
	pt.Y = this->Y + p.Y;

	return pt;
}

Point Point::operator-(const Point& p)
{
	Point pt;
	pt.X = X - p.X;
	pt.Y = Y - p.Y;

	return pt;
}

Point Point::operator*(const Point& p)
{
	Point pt;
	pt.X = X * p.X;
	pt.Y = Y * p.Y;

	return pt;
}

Point Point::operator/(const Point& p)
{
	Point pt;
	pt.X = X / p.X;
	pt.Y = Y / p.Y;

	return pt;
}

//Point Point::operator=(const Point& p)
//{
//	Point pt;
//	pt.X = p.X;
//	pt.Y = p.Y;
//
//	return pt;
//}
//
//bool Point::operator==(const Point& p)
//{
//	return (X == p.X && Y == p.Y);
//}
//
//bool Point::operator!=(const Point& p)
//{
//	return !(X == p.X && Y == p.Y);
//}