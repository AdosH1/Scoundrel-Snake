#pragma once
#include "Dojo.hpp"

Dojo::Dojo(sf::RenderWindow* window, GameDirector* game)
{
	Window = window;
	Game = game;
}

Dojo::~Dojo()
{
	
}

void Dojo::Load()
{
	// Border walls
	Game->CreateWall(Window, Rectangle(Point(0, 0), Point(15, 600)), GameDirector::Middleground);
	Game->CreateWall(Window, Rectangle(Point(15, 0), Point(600, 15)), GameDirector::Middleground);
	Game->CreateWall(Window, Rectangle(Point(585, 15), Point(600, 600)), GameDirector::Middleground);
	Game->CreateWall(Window, Rectangle(Point(15, 585), Point(585, 600)), GameDirector::Middleground);
	// Background
	Game->CreateGhostRectangle(Window, Rectangle(Point(0, 0), Point(600, 600)), GraphicsFactory::pFloorTexture, GameDirector::Background, "Wooden Floor");
	// Creatures
	Game->CreateRat(Window, 300, 300, GameDirector::Middleground);
	Game->CreateRat(Window, 500, 500, GameDirector::Middleground);
}

void Dojo::Upkeep()
{
	if (Game->EnemyCount["Rat"] < 2) Game->CreateRat(Window, 250, 250);
}



