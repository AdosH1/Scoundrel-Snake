#pragma once


class Point
{
public:
	double X;
	double Y;

	Point();
	Point(int x, int y);
	Point(float x, float y);
	Point(double x, double y);
	~Point();

	Point operator*(const int& multiplier);
	Point operator*(const float& multiplier);
	Point operator*(const double& multiplier);
	Point operator+(const Point& p);
	Point operator-(const Point& p);
	Point operator*(const Point& p);
	Point operator/(const Point& p);

	//Point operator=(const Point& p);
	//bool operator==(const Point& p);
	//bool operator!=(const Point& p);

};