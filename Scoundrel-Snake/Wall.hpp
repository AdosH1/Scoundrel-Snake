#pragma once

#include "SFML/Graphics.hpp"
#include "IDrawable.hpp"
#include "IGameObject.hpp"
#include "../Utility/Rectangle.hpp"

class Wall : IGameObject, IDrawable
{
public:
	Wall(sf::RenderWindow* renderWindow);
	Wall(sf::RenderWindow* renderWindow, int x1, int y1, int x2, int y2);
	Wall(sf::RenderWindow* renderWindow, float x1, float y1, float x2, float y2);
	Wall(sf::RenderWindow* renderWindow, double x1, double y1, double x2, double y2);
	Wall(sf::RenderWindow* renderWindow, Point p1, Point p2);
	Wall(sf::RenderWindow* renderWindow, Rectangle rect);

	/* The window this object belongs to */
	sf::RenderWindow *Window;

	Rectangle Geo;
	sf::RectangleShape Rect;

	void Draw() override;
};
