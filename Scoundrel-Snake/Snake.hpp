#pragma once

#include <deque>
#include "SFML/Graphics.hpp"
#include "IDrawable.hpp"
#include "IGameObject.hpp"
#include "../Utility/Point.hpp"

class Snake : public IDrawable, public IGameObject
{
    public:
		/* The window this object belongs to */
		sf::RenderWindow *Window;

		/* Current head position */
        Point Pos;
		/* A deque of all tail positions */
		std::deque<Point> TailPos;
		/* Snake speed in pixels */
        float Speed;
	    /* The number of tail segments the snake will have */
        int TailLength;

		sf::CircleShape Head;
		sf::CircleShape Tail;

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
        const float HeadRadius = 8;
        const float TailRadius = 6;
		/* The distance between each tail segment (in pixels (roughly) ) */
		const int TailSegmentDistance = 2;
		int TailSegmentCounter = 0;

        Point LastPos;


};


