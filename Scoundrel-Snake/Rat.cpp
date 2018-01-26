#pragma once
#include "Rat.hpp"
#include "GraphicsFactory.hpp"

#pragma region Constructors
Rat::Rat(sf::RenderWindow *renderWindow, float x, float y)
{
	Window = renderWindow;

	Pos.X = x;
	Pos.Y = y;
	Speed = 3;

	/* Initialise Graphics */
	Head = sf::CircleShape(HeadRadius);
	Head.setTexture(GraphicsFactory::pRatHeadS);
	Head.setPosition(x - HeadRadius, y - HeadRadius);
}

Rat::Rat(sf::RenderWindow *renderWindow, float x, float y, float speed)
{
	Window = renderWindow;

	Pos.X = x;
	Pos.Y = y;
    Speed = speed;

	/* Initialise Graphics */
	Head = sf::CircleShape(HeadRadius);
	Head.setTexture(GraphicsFactory::pRatHeadS);
	Head.setPosition(x - HeadRadius, y - HeadRadius);
}
#pragma endregion 

void Rat::ChooseDirection() 
{
    dir = rand() % 5;
	step = rand() % 10 + 1;
}

void Rat::Move() 
{
	LastPos = Pos;
    switch(dir) 
	{
        case 0: //STOP
            break;
        case 1: //UP
            Pos.Y -= Speed;
			Head.setTexture(GraphicsFactory::pRatHeadN);
			break;
        case 2: //LEFT
            Pos.X -= Speed;
			Head.setTexture(GraphicsFactory::pRatHeadW);
			break;
        case 3: //DOWN
            Pos.Y += Speed;
			Head.setTexture(GraphicsFactory::pRatHeadS);
			break;
        case 4: //RIGHT
            Pos.X += Speed;
			Head.setTexture(GraphicsFactory::pRatHeadE);
			break;
		default:
			break;
    } 
	step--;
}

void Rat::PlayTurn()
{
	if (step <= 0) ChooseDirection();
	Move();
}

void Rat::Draw()
{
	Head.setPosition(Pos.X - HeadRadius, Pos.Y - HeadRadius);
	Window->draw(Head);
}

//int Rat::checkhit(sf::Vector2f s_pos, const int s_r, std::deque<float> x, std::deque<float> y, const int t_r)
//{
//    hit = false;
//
//    d = (int)sqrt( pow(s_Pos.X - Pos.X, 2) + pow(s_Pos.Y - Pos.Y, 2)); //check relative distance between snake and rat
//    if (d <= (s_r + HeadRadius))
//    {
//        hit = true;
//        return 1;
//    }
//
//    for (int i = 0; i < x.size(); i++)
//    {
//        d = (int)sqrt( pow(x.at(i) - Pos.X, 2) + pow(y.at(i) - Pos.Y, 2) ); //check relative distance between tail segment and rat
//        if (d <= (t_r + HeadRadius))
//        {
//            hit = true;
//            return 2;
//        }
//    }
//    if(hit == false)
//        return 0;
//}


