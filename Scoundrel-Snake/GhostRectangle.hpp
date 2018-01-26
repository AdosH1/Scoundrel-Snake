#pragma once

#include "SFML/Graphics.hpp"
#include "IDrawable.hpp"
#include "../Utility/Rectangle.hpp"

class GhostRectangle : public IDrawable
{
public:
	GhostRectangle(sf::RenderWindow* renderWindow, sf::Texture* texture = NULL, std::string name = "");
	GhostRectangle(sf::RenderWindow* renderWindow, int x1, int y1, int x2, int y2, sf::Texture* texture = NULL, std::string name = "");
	GhostRectangle(sf::RenderWindow* renderWindow, float x1, float y1, float x2, float y2, sf::Texture* texture = NULL, std::string name = "");
	GhostRectangle(sf::RenderWindow* renderWindow, double x1, double y1, double x2, double y2, sf::Texture* texture = NULL, std::string name = "");
	GhostRectangle(sf::RenderWindow* renderWindow, Point p1, Point p2, sf::Texture* texture = NULL, std::string name = "");
	GhostRectangle(sf::RenderWindow* renderWindow, Rectangle rect, sf::Texture* texture = NULL, std::string name = "");

	/* The window this object belongs to */
	sf::RenderWindow *Window;

	std::string Name;
	Rectangle Geo;
	sf::RectangleShape Rect;

	void Draw() override;
};