#pragma once
#include <list>
#include "IGameObject.hpp"
#include "IDrawable.hpp"
#include "Snake.hpp"
#include "Rat.hpp"
#include <vector>

class GameDirector
{
public:
	std::list<IGameObject*> currentGameObjects;
	std::list<IDrawable*> currentDrawObjects;

	GameDirector();

	void AddGameObject(IGameObject *object);
	void AddDrawObject(IDrawable *object);
	void DrawGameObjects();
	void GameTurn();

	Rat* CreateRat(sf::RenderWindow *renderWindow, float x, float y);
	Snake* CreateSnake(sf::RenderWindow *renderWindow, float x, float y);

	void Reset();
	void Remove(IObject *object);
	void RemoveGameObject(IGameObject *object);
	void RemoveDrawObject(IDrawable *object);

	
};
