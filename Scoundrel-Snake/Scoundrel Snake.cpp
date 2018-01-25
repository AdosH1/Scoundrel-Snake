////Scoundrel Snake, a reimagining of the classic game snake
//// By Aden Huen
//
//
#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>

#include "Snake.hpp"
#include "GameDirector.hpp"
#include "GraphicsFactory.hpp"
#include "Rat.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "PlayerControl.hpp"

void LoadDojo(sf::RenderWindow *Window, GameDirector *Game)
{
	Game->CreateWall(Window, Rectangle(Point(0, 0), Point(15, 600)));
	Game->CreateWall(Window, Rectangle(Point(15, 0), Point(600, 15)));
	Game->CreateWall(Window, Rectangle(Point(585, 15), Point(600, 600)));
	Game->CreateWall(Window, Rectangle(Point(15, 585), Point(585, 600)));

	//Game->CreateWall(Window, Rectangle(Point(250, 250), Point(350, 350)));
}

int main() 
{
	/* Initialization */
	sf::Vector2<int> windowSize;
	windowSize.x = 600;
	windowSize.y = 600;
	const int border_width = 12;
	sf::RenderWindow Window(sf::VideoMode(windowSize.x, windowSize.y), "Scoundrel Snake");
	Window.setFramerateLimit(30);

	srand((unsigned)time(NULL));
	sf::Event event;

	/* Game objects */
	GameDirector *Game = new GameDirector();
	GraphicsFactory *Graphics = new GraphicsFactory(windowSize.x, windowSize.y, border_width);
	Graphics->Initialise();

	Snake *s = Game->CreateSnake(&Window, 50, 50);
	Rat *r = Game->CreateRat(&Window, 300, 300);

	LoadDojo(&Window, Game);

	while (Window.isOpen())
	{
		if (s != NULL) PlayerControl::PlayerAction(s);
		Game->GameTurn();

		//Draw game objects
		Window.clear();
		Game->DrawGameObjects();
		Window.display();

		//If the window is crossed, exit the window
		while (Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Window.close();
		}
	}
	return 0;
}

//
//
//void randvect(sf::Vector2f& vect, const int window_x, const int window_y, const int border_width)
//{
//    vect.x = rand() % 500 + 50;
//    vect.y = rand() % 500 + 50;
//}
//
//bool isAnyKeyPressed()
//	{
//		for (int k = -1; k < sf::Keyboard::KeyCount; ++k)
//		{
//			if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(k)))
//				return true;
//		}
//		return false;
//	}
//