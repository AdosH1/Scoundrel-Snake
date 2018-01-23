#pragma once

#include "Snake.hpp"
#include "GraphicsFactory.hpp"

Snake::Snake(sf::RenderWindow *renderWindow, float x, float y)
{
	Window = renderWindow;

	Pos.x = x + HeadRadius;
	Pos.y = y + HeadRadius;
	Speed = 4;
	TailLength = 6;

	for (int i = 0; i < TailLength; ++i) 
	{
		TailPos.push_back(sf::Vector2<float>(-10, -10));
	}

	LastPos.x = -10;
	LastPos.y = -10;

	/* Initialise Graphics */
	Head = sf::CircleShape(HeadRadius);
	Head.setTexture(GraphicsFactory::pSnakeHeadS);
	Head.setPosition(Pos.x, Pos.y);

	Tail = sf::CircleShape(TailRadius);
	Tail.setTexture(GraphicsFactory::pSnakeBody);
};

Snake::Snake(sf::RenderWindow *renderWindow, float x, float y, float speed, int tailLength)
{
	Window = renderWindow;

    Pos.x = x + HeadRadius;
    Pos.y = y + HeadRadius;
    Speed = speed;
    TailLength = tailLength;

    for (int i = 0; i < TailLength; ++i) 
	{
        TailPos.push_back(sf::Vector2<float>(0,0));
    }

    LastPos.x = -10;
    LastPos.y = -10;

	/* Initialise Graphics */
	Head = sf::CircleShape(HeadRadius);
	Head.setTexture(GraphicsFactory::pSnakeHeadS);
	Head.setPosition(Pos.x, Pos.y);

	Tail = sf::CircleShape(TailRadius);
	Tail.setTexture(GraphicsFactory::pSnakeBody);
};

Snake::~Snake() 
{

}

void Snake::Draw()
{
	/* Draw Tail */
	for (int i = 0; i < TailLength; i++)
	{
		//TODO: figure out why we need a 2.0f offset to draw tail correctly
		Tail.setPosition(TailPos[i].x + 2.0f, TailPos[i].y + 2.0f);
		Window->draw(Tail);
	}
	/* Draw Head */
	Head.setPosition(Pos.x, Pos.y);
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
    sf::Vector2<float> pos(-10,-10);

    for (int i = 0; i < length; ++i) {
        TailPos.push_back(pos);
    }
}

// Checks collision of the head with the tail
bool Snake::TailHitByHead()
{
    for (int i = 18; i < TailPos.size(); i++)
    {
        float distance = sqrt(pow(TailPos.at(i).x - Pos.x, 2) + pow(TailPos.at(i).y - Pos.y, 2));
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
