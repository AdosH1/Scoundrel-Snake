#pragma once
#include "IDrawable.hpp"
#include "IGameObject.hpp"
#include "SFML/Graphics.hpp"
#include "../Utility/Rectangle.hpp"
#include "GraphicsFactory.hpp"


class Cheese : public IGameObject, public IDrawable
{
public:
	/* The window this object belongs to */
	sf::RenderWindow *Window;

	/* Base Class Implementations*/
	Point GetPosition() override;
	std::deque<Point> GetPositionList() override;
	Point GetLastPosition() override;
	double GetSpeed() override;
	bool GetDispose() override;

	bool SetPosition(Point pos) override;
	bool SetLastPosition(Point pos) override;
	bool SetSpeed(double speed) override;
	bool SetDispose(bool dispose) override;

	bool Update(int input) override;

	Cheese(sf::RenderWindow *renderWindow, double x, double y);
	~Cheese();

	Point Pos;
	Point LastPos;
	Rectangle Geo;
	sf::RectangleShape CheeseShape;
	bool Dispose = false;

	void Draw() override;
};