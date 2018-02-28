#pragma once
#include "Menu.hpp"

Menu::Menu(sf::RenderWindow* window, GameDirector* game, IGameObject* player)
{
	Window = window;
	Game = game;
	Player = player;
	MapSize = Rectangle(Point(0, 0), Point(600, 600));
}

Menu::~Menu()
{
	
}

void Menu::Load()
{
	Game->Reset();
	PlayerControl::GameMode = PlayerControl::Menu;

	Rectangle menu = Rectangle(0, 0, 600, 600);
	Game->CreateGhostRectangle(Window, menu, GraphicsFactory::pMenuScreenTexture, Game->Background, "MenuScreen");

	Rectangle playButton = Rectangle(0, 0, 100, 60);
	GhostRectangle* play = Game->CreateGhostRectangle(Window, playButton, GraphicsFactory::pPlayButtonTexture, Game->Foreground, "PlayButton");
	play->Geo.MoveTopLeftTo(Point(100, 400));

	Rectangle exitButton = Rectangle(0, 0, 100, 60);
	GhostRectangle* exit = Game->CreateGhostRectangle(Window, exitButton, GraphicsFactory::pExitButtonTexture, Game->Foreground, "ExitButton");
	exit->Geo.MoveTopLeftTo(Point(100, 480));

	Rectangle selector = Rectangle(0, 0, 25, 25);
	GhostRectangle* select = Game->CreateGhostRectangle(Window, selector, GraphicsFactory::pSelectorTexture, Game->Foreground, "Selector");
	select->Geo.MoveCenterTo(Point(80, 370));
}

void Menu::Upkeep()
{
	
}



