#include "stdafx.h"
#include "Rectangle.hpp"

Rectangle::Rectangle()
{
	Min = Point(0, 0);
	Max = Point(1, 1);

	Center = Point((Max.X + Min.X) / 2, (Max.Y + Min.Y) / 2);
	Height = abs(Max.Y - Min.Y);
	Width = abs(Max.X - Min.X);
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2)
{
	Min.X = fmin(x1, x2);
	Min.Y = fmin(y1, y2);
	Max.X = fmax(x1, x2);
	Max.Y = fmax(y1, y2);

	Center = Point((Max.X + Min.X) / 2, (Max.Y + Min.Y) / 2);
	Height = abs(Max.Y - Min.Y);
	Width = abs(Max.X - Min.X);
}

Rectangle::Rectangle(float x1, float y1, float x2, float y2)
{
	Min.X = fmin(x1, x2);
	Min.Y = fmin(y1, y2);
	Max.X = fmax(x1, x2);
	Max.Y = fmax(y1, y2);

	Center = Point((Max.X + Min.X) / 2, (Max.Y + Min.Y) / 2);
	Height = abs(Max.Y - Min.Y);
	Width = abs(Max.X - Min.X);
}

Rectangle::Rectangle(double x1, double y1, double x2, double y2)
{
	Min.X = fmin(x1, x2);
	Min.Y = fmin(y1, y2);
	Max.X = fmax(x1, x2);
	Max.Y = fmax(y1, y2);

	Center = Point((Max.X + Min.X) / 2, (Max.Y + Min.Y) / 2);
	Height = abs(Max.Y - Min.Y);
	Width = abs(Max.X - Min.X);
}

Rectangle::Rectangle(Point p1, Point p2)
{
	Min.X = fmin(p1.X, p2.X);
	Min.Y = fmin(p1.Y, p2.Y);
	Max.X = fmax(p1.X, p2.X);
	Max.Y = fmax(p1.Y, p2.Y);

	Center = Point((Max.X + Min.X) / 2, (Max.Y + Min.Y) / 2);
	Height = abs(Max.Y - Min.Y);
	Width = abs(Max.X - Min.X);
}

Rectangle::~Rectangle() = default;

void Rectangle::MoveTopLeftTo(Point p)
{
	Min.X = p.X;
	Max.Y = p.Y;
	Min.Y = p.Y - Height;
	Max.X = p.X + Width;
	// Recalculate center
	Center = Point((Max.X + Min.X) / 2, (Max.Y + Min.Y) / 2);
}

void Rectangle::MoveCenterTo(Point p)
{
	Center = p;

	Min.X = p.X - (Width / 2);
	Min.Y = p.Y - (Height / 2);
	Max.X = p.X + (Width / 2);
	Max.Y = p.Y + (Height / 2);
}

