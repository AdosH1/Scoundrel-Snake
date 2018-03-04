#pragma once
#include <list>
#include "IGameObject.hpp"
#include "IDrawable.hpp"
#include "Snake.hpp"
#include "Rat.hpp"
#include <vector>
#include "Wall.hpp"
#include "GhostRectangle.hpp"

class GameDirector
{
public:
	sf::RenderWindow* Window;
	bool GameOver;
	enum DrawLevel { Background = 0, Middleground = 1, Foreground = 2 };
	std::map<std::string, int> EnemyCount;

	std::vector<IGameObject*> CurrentGameObjects;
	std::vector<IEnvironmentObject*> CurrentEnvironmentObjects;
	std::vector<std::list<IDrawable*>*> CurrentDrawObjects;

	std::list<IDrawable*> ForegroundDrawObjects;
	std::list<IDrawable*> MiddlegroundDrawObjects;
	std::list<IDrawable*> BackgroundDrawObjects;

	GameDirector(sf::RenderWindow* window);
	~GameDirector();

	void AddGameObject(IGameObject *object);
	void AddDrawObject(IDrawable *object);
	void DrawGameObjects();

	Rat* CreateRat(sf::RenderWindow *renderWindow, float x, float y, DrawLevel drawLevel = Middleground);
	Snake* CreateSnake(sf::RenderWindow *renderWindow, float x, float y, DrawLevel drawLevel = Middleground);
	Wall* CreateWall(sf::RenderWindow *renderWindow, Rectangle rect, DrawLevel drawLevel = Middleground);

	GhostRectangle* CreateGhostRectangle(sf::RenderWindow *renderWindow, Rectangle rect, sf::Texture* texture = NULL, DrawLevel drawLevel = Middleground, std::string name = "");

	void GameTurn();
	void Referee();
	void Cleanup();

	void LoadMenu(sf::RenderWindow *renderWindow);

	void Reset();
	void Remove(IObject *object);
	void RemoveGameObject(IGameObject *object);
	void RemoveDrawObject(IDrawable *object);

	
};
