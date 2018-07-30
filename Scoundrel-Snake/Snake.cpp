#pragma once

#include "Snake.hpp"

#pragma region Constructors / Destructors
Snake::Snake(sf::RenderWindow *renderWindow, float x, float y)
{
	Window = renderWindow;

	Pos.X = x;
	Pos.Y = y;
	Speed = 6;
	TailLength = 4;

	for (int i = 0; i < TailLength; ++i) 
	{
		TailPos.push_back(Point(-10,-10));
	}

	LastPos.X = -10;
	LastPos.Y = -10;

	/* Initialise Graphics */
	Head = sf::CircleShape(HeadRadius);
	Head.setTexture(GraphicsFactory::pSnakeHeadS);
	Head.setPosition(x - HeadRadius,y - HeadRadius);

	Tail = sf::CircleShape(TailRadius);
	Tail.setTexture(GraphicsFactory::pSnakeBody);
};

Snake::Snake(sf::RenderWindow *renderWindow, float x, float y, float speed, int tailLength)
{
	Window = renderWindow;

    Pos.X = x;
    Pos.Y = y;
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
	Head.setPosition(Pos.X - HeadRadius, Pos.Y - HeadRadius);

	Tail = sf::CircleShape(TailRadius);
	Tail.setTexture(GraphicsFactory::pSnakeBody);
};

Snake::~Snake() 
{

}

#pragma endregion 

Point Snake::GetPosition()
{
	return Pos;
}

std::deque<Point> Snake::GetPositionList()
{
	return TailPos;
}

Point Snake::GetLastPosition()
{
	return LastPos;
}

double Snake::GetSpeed()
{
	return Speed;
}

bool Snake::GetDispose()
{
	return Dispose;
}

bool Snake::SetDispose(bool dispose)
{
	Dispose = dispose;
	return true;
}


bool Snake::SetPosition(Point pos)
{
	Pos = pos;
	return true;
}

bool Snake::SetLastPosition(Point pos)
{
	LastPos = pos;
	return true;
}

bool Snake::SetSpeed(double speed)
{
	Speed = speed;
	return true;
}

bool Snake::Update(int input = 0)
{
	UpdateHeadTexture(input);
	UpdateTail();
	return true;
}

void Snake::Draw()
{
	/* Draw Tail */
	for (int i = 0; i < TailLength; i++)
	{
		Tail.setPosition(TailPos[i].X - TailRadius, TailPos[i].Y - TailRadius);
		Window->draw(Tail);
	}

	/* Draw Head */
	Head.setPosition(Pos.X - HeadRadius, Pos.Y - HeadRadius);
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
	TailLength += length;
}

void Snake::Shorten(int length)
{
	if (TailLength <= length) return;
	for (int i = 0; i < length; ++i) {
		TailPos.pop_back();
	}
	TailLength -= length;
}


// Checks collision of the head with the tail
bool Snake::TailHitByHead()
{
    for (int i = 6; i < TailPos.size(); i++)
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
		if (HitWall)
		{
			TailSegmentCounter++;
			HitWall = false;
		}
		else
		{
			TailPos.pop_back();
			TailPos.push_front(Pos);
			TailSegmentCounter = 0;
		}
	}
	else TailSegmentCounter++;
}
