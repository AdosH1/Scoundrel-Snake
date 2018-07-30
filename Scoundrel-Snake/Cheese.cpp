#include "Cheese.hpp"


Cheese::Cheese(sf::RenderWindow* renderWindow, double x, double y)
{
	Window = renderWindow;
	Pos = Point(x, y);
	LastPos = Pos;
	Geo = Rectangle(Point(Pos.X - 8, Pos.Y - 8), Point(Pos.X + 8, Pos.Y + 8));

	CheeseShape = sf::RectangleShape(sf::Vector2f(16, 16));
	CheeseShape.setTexture(GraphicsFactory::pCheese);
}

Cheese::~Cheese()
{
	
}

void Cheese::Draw()
{
	CheeseShape.setPosition(Pos.X, Pos.Y);
	Window->draw(CheeseShape);
}

bool Cheese::GetDispose()
{
	return Dispose;
}

Point Cheese::GetPosition()
{
	return Pos;
}

bool Cheese::SetPosition(Point pos)
{
	Pos = pos;
	return true;
}

bool Cheese::SetLastPosition(Point pos)
{
	LastPos = pos;
	return true;
}

Point Cheese::GetLastPosition()
{
	return LastPos;
}

bool Cheese::SetDispose(bool dispose)
{
	Dispose = dispose;
	return true;
}

std::deque<Point> Cheese::GetPositionList()
{
	return std::deque<Point>();
}

double Cheese::GetSpeed()
{
	return 0;
}

bool Cheese::SetSpeed(double speed)
{
	return false;
}

bool Cheese::Update(int input)
{
	return false;
}










