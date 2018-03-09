#pragma once

#include <deque>
#include "SFML/Graphics.hpp"
#include "GraphicsFactory.hpp"
#include "IDrawable.hpp"
#include "IGameObject.hpp"
#include "../Utility/Point.hpp"

class Snake : public IDrawable, public IGameObject
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

		/* Current head position */
        Point Pos;
		const double HeadRadius = 8;
		const double TailRadius = 5;
		Point LastPos;

		/* A deque of all tail positions */
		std::deque<Point> TailPos;
		/* Snake speed in pixels */
        float Speed;
	    /* The number of tail segments the snake will have */
        int TailLength;
		bool HitWall = false;

		sf::CircleShape Head;
		sf::CircleShape Tail;
		bool Dispose = false;

		/* Constructors / Destructors */
		Snake(sf::RenderWindow *renderWindow, float x, float y);
		Snake(sf::RenderWindow *renderWindow, float x, float y, float speed, int tailLength);
		~Snake();

		void Draw() override;
		void UpdateHeadTexture(int enumValue);
		void Lengthen(int length);
		bool TailHitByHead();
		void UpdateTail();

    private:
		/* The distance between each tail segment (in pixels (roughly) ) */
		const int TailSegmentDistance = 1;
		int TailSegmentCounter = 0;


};


