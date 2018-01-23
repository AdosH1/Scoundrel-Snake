#include "stdafx.h"
#include "Rectangle.hpp"

Rectangle::Rectangle()
{
	MinPt.X = 0;
	MinPt.Y = 0;
	MinPt.X = 1;
	MaxPt.X = 1;
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2)
{
	MinPt.X = x1;
	MinPt.Y = y1;
	MinPt.X = x2;
	MaxPt.X = y2;
}

Rectangle::Rectangle(float x1, float y1, float x2, float y2)
{
	MinPt.X = x1;
	MinPt.Y = y1;
	MinPt.X = x2;
	MaxPt.X = y2;
}

Rectangle::Rectangle(double x1, double y1, double x2, double y2)
{
	MinPt.X = x1;
	MinPt.Y = y1;
	MinPt.X = x2;
	MaxPt.X = y2;
}

Rectangle::Rectangle(Point minPt, Point maxPt)
{
	MinPt = minPt;
	MaxPt = maxPt;
}

Rectangle::~Rectangle()
{

}