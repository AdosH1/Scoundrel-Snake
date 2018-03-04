////InGame Snake, a reimagining of the classic game snake
//// By Aden Huen
//
// TODO: Snake hit -> Menu Screen, Update IMap to support exit
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
#include "IMap.hpp"
#include "MenuScreen.hpp"
#include "Dojo.hpp"

void ChangeMap(sf::RenderWindow* window, GameDirector* game, IGameObject* player, IMap* nextMap)
{
	nextMap->Initialize(window, game, PlayerControl::Player, nextMap);
	nextMap->Load();
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
	GameDirector *Game = new GameDirector(&Window);
	GraphicsFactory *Graphics = new GraphicsFactory(windowSize.x, windowSize.y, border_width);
	Graphics->Initialise();
	
	//PlayerControl::Player = Game->CreateSnake(&Window, 50, 50, GameDirector::Middleground);
	IMap* CurrentMap = new MenuScreen();
	CurrentMap->Initialize(&Window, Game, PlayerControl::Player, CurrentMap);
	CurrentMap->Load();

	while (Window.isOpen())
	{
		PlayerControl::PlayerAction();
		Game->GameTurn();
		CurrentMap->Upkeep();

		if (CurrentMap->GetChange())
		{
			ChangeMap(&Window, Game, PlayerControl::Player, CurrentMap->GetMap());
			CurrentMap = CurrentMap->GetMap();
		}
		if (CurrentMap->GetExit())
		{
			// If Exit is called in Menu Screen
			if(MenuScreen *menuscreen = dynamic_cast<MenuScreen*>(CurrentMap->GetMap())) Window.close();
			else //if (Dojo *menuscreen = dynamic_cast<Dojo*>(CurrentMap->GetMap()))
			{
				CurrentMap = new MenuScreen();
				CurrentMap->Initialize(&Window, Game, PlayerControl::Player, CurrentMap);
				CurrentMap->Load();
			}
		}
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