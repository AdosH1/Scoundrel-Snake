#pragma once

#include "Snake.hpp"
#include "GraphicsFactory.hpp"

#pragma region Constructors / Destructors
Snake::Snake(sf::RenderWindow *renderWindow, float x, float y)
{
	Window = renderWindow;

	Pos.X = x + HeadRadius;
	Pos.Y = y + HeadRadius;
	Speed = 4;
	TailLength = 6;

	for (int i = 0; i < TailLength; ++i) 
	{
		TailPos.push_back(Point(-10,-10));
	}

	LastPos.X = -10;
	LastPos.Y = -10;

	/* Initialise Graphics */
	Head = sf::CircleShape(HeadRadius);
	Head.setTexture(GraphicsFactory::pSnakeHeadS);
	Head.setPosition(Pos.X, Pos.Y);

	Tail = sf::CircleShape(TailRadius);
	Tail.setTexture(GraphicsFactory::pSnakeBody);
};

Snake::Snake(sf::RenderWindow *renderWindow, float x, float y, float speed, int tailLength)
{
	Window = renderWindow;

    Pos.X = x + HeadRadius;
    Pos.Y = y + HeadRadius;
    Speed = speed;
    TailLength = tailLength;

    for (int i = 0; i < TailLength; ++i) 
	{
        TailPos.push_back(Point(0,0));
    }

    LastPos.X = -10;
    LastPos.Y = -10;

	/* Initialise Graphics */
	Head = sf::CircleShape(HeadRadius);
	Head.setTexture(GraphicsFactory::pSnakeHeadS);
	Head.setPosition(Pos.X, Pos.Y);

	Tail = sf::CircleShape(TailRadius);
	Tail.setTexture(GraphicsFactory::pSnakeBody);
};

Snake::~Snake() 
{

}

#pragma endregion 

void Snake::Draw()
{
	/* Draw Tail */
	for (int i = 0; i < TailLength; i++)
	{
		//TODO: figure out why we need a 2.0f offset to draw tail correctly
		Tail.setPosition(TailPos[i].X + 2.0f, TailPos[i].Y + 2.0f);
		Window->draw(Tail);
	}
	/* Draw Head */
	Head.setPosition(Pos.X, Pos.Y);
	Window->draw(Head);
}

// Update the head texture based on the direction the snake is moving
void Snake::UpdateHeadTexture(int enumValue)
{
	switch (enumValue)
	{
		case 0:
			break;
		case 1: // North
			Head.setTexture(GraphicsFactory::pSnakeHeadN);
			break;
		case 2: // East
			Head.setTexture(GraphicsFactory::pSnakeHeadE);
			break;
		case 3: // South
			Head.setTexture(GraphicsFactory::pSnakeHeadS);
			break;
		case 4: // West
			Head.setTexture(GraphicsFactory::pSnakeHeadW);
			break;
		case 5: // North-East
			Head.setTexture(GraphicsFactory::pSnakeHeadNE);
			break;
		case 6: // South-East
			Head.setTexture(GraphicsFactory::pSnakeHeadSE);
			break;
		case 7: // South-West
			Head.setTexture(GraphicsFactory::pSnakeHeadSW);
			break;
		case 8: // North-West
			Head.setTexture(GraphicsFactory::pSnakeHeadNW);
			break;
		default:
			break;
	}
}

// Make the tail 'length' segments longer
void Snake::Lengthen(int length) 
{
	Point pos = Point(-10, -10);

    for (int i = 0; i < length; ++i) {
        TailPos.push_back(pos);
    }
}

// Checks collision of the head with the tail
bool Snake::TailHitByHead()
{
    for (int i = 18; i < TailPos.size(); i++)
    {
        float distance = sqrt(pow(TailPos.at(i).X - Pos.X, 2) + pow(TailPos.at(i).Y - Pos.Y, 2));
        if (distance < (HeadRadius + TailRadius)) return true;
    }
    return false;
}

void Snake::UpdateTail() 
{
	if (TailSegmentCounter >= TailSegmentDistance)
	{
		TailPos.pop_back();
		TailPos.push_front(Pos);
		TailSegmentCounter = 0;
	}
	else TailSegmentCounter++;
}
