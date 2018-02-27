#pragma once
#include "Dojo.hpp"

Dojo::Dojo(sf::RenderWindow* window, GameDirector* game, IGameObject* player)
{
	Window = window;
	Game = game;
	MapSize = Rectangle(Point(23, 23), Point(577, 577)); // playable map size
	Player = player;
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
	Game->CreateRat(Window, 350, 350, GameDirector::Middleground);
	Game->CreateRat(Window, 500, 500, GameDirector::Middleground);
}

void Dojo::Upkeep()
{
	if (Game->EnemyCount["Rat"] < 2)
	{
		Point p = Geometry::RandomPointWithinRectangleAwayFromPoint(MapSize, Player->Position(), 100);
		Game->CreateRat(Window, p.X, p.Y);
	}
}



