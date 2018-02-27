////InGame Snake, a reimagining of the classic game snake
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
#include "Dojo.hpp"

void Menu(sf::RenderWindow *Window, GameDirector *Game)
{
	Game->Reset();
	Game->LoadMenu(Window);

}

void PlayerTurn(sf::RenderWindow *Window, GameDirector *Game, Snake *s)
{
	PlayerControl::PlayerAction(s);

	if (PlayerControl::prevInput == PlayerControl::Respawn)
	{
		if (s == NULL)
		{
			Game->CreateSnake(Window, 10, 10);
		}
	}
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

	Snake *s = Game->CreateSnake(&Window, 50, 50, GameDirector::Middleground);

	IMap* CurrentMap = new Dojo(&Window, Game, s);
	CurrentMap->Load();
	PlayerControl::GameMode = PlayerControl::InGame;

	while (Window.isOpen())
	{
		PlayerTurn(&Window, Game, s);
		Game->GameTurn();
		CurrentMap->Upkeep();

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