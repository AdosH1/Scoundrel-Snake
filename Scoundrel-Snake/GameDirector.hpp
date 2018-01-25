#pragma once
#include <list>
#include "IGameObject.hpp"
#include "IDrawable.hpp"
#include "Snake.hpp"
#include "Rat.hpp"
#include <vector>
#include "Wall.hpp"

class GameDirector
{
public:
	std::list<IGameObject*> currentGameObjects;
	std::list<IEnvironmentObject*> currentEnvironmentObjects;
	std::list<IDrawable*> currentDrawObjects;

	GameDirector();
	~GameDirector();

	void AddGameObject(IGameObject *object);
	void AddDrawObject(IDrawable *object);
	void DrawGameObjects();

	Rat* CreateRat(sf::RenderWindow *renderWindow, float x, float y);
	Snake* CreateSnake(sf::RenderWindow *renderWindow, float x, float y);
	Wall* CreateWall(sf::RenderWindow *renderWindow, Rectangle rect);

	void GameTurn();
	void Referee();

	void Reset();
	void Remove(IObject *object);
	void RemoveGameObject(IGameObject *object);
	void RemoveDrawObject(IDrawable *object);

	
};
