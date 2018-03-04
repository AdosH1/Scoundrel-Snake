#pragma once
#include "MenuScreen.hpp"

MenuScreen::MenuScreen()
{
	
}

MenuScreen::~MenuScreen()
{
	
}

void MenuScreen::Initialize(sf::RenderWindow* window, GameDirector* game, IGameObject* player, IMap* currentMap)
{
	Window = window;
	Game = game;
	Player = player;
	MapSize = Rectangle(Point(0, 0), Point(600, 600));
	Option = Play;
	CurrentMap = currentMap;
	ChangeMap = false;
}

void MenuScreen::Load()
{
	Game->Reset();
	PlayerControl::GameMode = PlayerControl::Menu;

	Rectangle menu = Rectangle(0, 0, 600, 600);
	Game->CreateGhostRectangle(Window, menu, GraphicsFactory::pMenuScreenTexture, Game->Background, "MenuScreen");

	Rectangle playRect = Rectangle(0, 0, 100, 60);
	playButton = Game->CreateGhostRectangle(Window, playRect, GraphicsFactory::pPlayButtonTexture, Game->Foreground, "PlayButton");
	playButton->Geo.MoveTopLeftTo(Point(100, 400));

	Rectangle exitRect = Rectangle(0, 0, 100, 60);
	exitButton = Game->CreateGhostRectangle(Window, exitRect, GraphicsFactory::pExitButtonTexture, Game->Foreground, "ExitButton");
	exitButton->Geo.MoveTopLeftTo(Point(100, 480));

	Rectangle selectRect = Rectangle(0, 0, 25, 25);
	selector = Game->CreateGhostRectangle(Window, selectRect, GraphicsFactory::pSelectorTexture, Game->Foreground, "Selector");
	selector->Geo.MoveCenterTo(Point(80, 370));

	PlayerControl::Player = new Placeholder();
}

bool MenuScreen::GetChange()
{
	return ChangeMap;


}

IMap* MenuScreen::GetMap()
{
	return CurrentMap;
}

bool MenuScreen::GetExit()
{
	return ExitMap;
}


void MenuScreen::Upkeep()
{
	int option = (int)Option;
	// Player action
	if (PlayerControl::currInput == PlayerControl::Up) option--;
	else if (PlayerControl::currInput == PlayerControl::Down) option++;

	if (option < 0) option = 0;
	if (option > 1) option = 1;

	Option = (MenuOptions)option;

	// Menu reaction
	if (Option == Play) selector->Geo.MoveCenterTo(Point(80, 370));
	if (Option == Exit) selector->Geo.MoveCenterTo(Point(80, 450));

	if (PlayerControl::currInput == PlayerControl::Enter)
	{
		if (Option == Play)
		{
			CurrentMap = new Dojo();
			ChangeMap = true;
		}
		else if (Option == Exit)
		{
			ExitMap = true;
		}
	}
}



