#include "GhostRectangle.hpp"
#include "../Utility/Geometry.hpp"
#include "GraphicsFactory.hpp"

#pragma region Constructors
GhostRectangle::GhostRectangle(sf::RenderWindow* renderWindow, sf::Texture* texture, std::string name)
{
	Window = renderWindow;

	Name = name;
	Geo = Rectangle(Point(0, 0), Point(1, 1));
	Rect = sf::RectangleShape(sf::Vector2f(1, 1));
	if (texture == NULL) Rect.setTexture(GraphicsFactory::pBorderTexture);
	else Rect.setTexture(texture);
}

GhostRectangle::GhostRectangle(sf::RenderWindow* renderWindow, int x1, int y1, int x2, int y2, sf::Texture* texture, std::string name)
{
	Window = renderWindow;

	Point p1 = Point(x1, y1);
	Point p2 = Point(x2, y2);
	Point diff = Geometry::PointDifference(p1, p2);

	Name = name;
	Geo = Rectangle(p1, p2);
	Rect = sf::RectangleShape(sf::Vector2f(diff.X, diff.Y));
	if (texture == NULL) Rect.setTexture(GraphicsFactory::pBorderTexture);
	else Rect.setTexture(texture);
}

GhostRectangle::GhostRectangle(sf::RenderWindow* renderWindow, float x1, float y1, float x2, float y2, sf::Texture* texture, std::string name)
{
	Window = renderWindow;

	Point p1 = Point(x1, y1);
	Point p2 = Point(x2, y2);
	Point diff = Geometry::PointDifference(p1, p2);

	Name = name;
	Geo = Rectangle(p1, p2);
	Rect = sf::RectangleShape(sf::Vector2f(diff.X, diff.Y));
	if (texture == NULL) Rect.setTexture(GraphicsFactory::pBorderTexture);
	else Rect.setTexture(texture);
}

GhostRectangle::GhostRectangle(sf::RenderWindow* renderWindow, double x1, double y1, double x2, double y2, sf::Texture* texture, std::string name)
{
	Window = renderWindow;

	Point p1 = Point(x1, y1);
	Point p2 = Point(x2, y2);
	Point diff = Geometry::PointDifference(p1, p2);

	Name = name;
	Geo = Rectangle(p1, p2);
	Rect = sf::RectangleShape(sf::Vector2f(diff.X, diff.Y));
	if (texture == NULL) Rect.setTexture(GraphicsFactory::pBorderTexture);
	else Rect.setTexture(texture);
}

GhostRectangle::GhostRectangle(sf::RenderWindow* renderWindow, Point p1, Point p2, sf::Texture* texture, std::string name)
{
	Window = renderWindow;

	Point diff = Geometry::PointDifference(p1, p2);

	Name = name;
	Geo = Rectangle(p1, p2);
	Rect = sf::RectangleShape(sf::Vector2f(diff.X, diff.Y));
	if (texture == NULL) Rect.setTexture(GraphicsFactory::pBorderTexture);
	else Rect.setTexture(texture);
}

GhostRectangle::GhostRectangle(sf::RenderWindow* renderWindow, Rectangle rect, sf::Texture* texture, std::string name)
{
	Window = renderWindow;

	Point diff = Geometry::PointDifference(rect.Min, rect.Max);

	Name = name;
	Geo = rect;
	Rect = sf::RectangleShape(sf::Vector2f(diff.X, diff.Y));
	if (texture == NULL) Rect.setTexture(GraphicsFactory::pBorderTexture);
	else Rect.setTexture(texture);
}

#pragma endregion 

void GhostRectangle::Draw()
{
	Rect.setPosition(Geo.Min.X, Geo.Min.Y);
	Window->draw(Rect);
}