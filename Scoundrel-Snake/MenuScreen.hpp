#pragma once
#include "IMap.hpp"
#include "GameDirector.hpp"
#include "PlayerControl.hpp"
#include "Dojo.hpp"

class MenuScreen : public IMap
{
public:
	//MenuScreen(sf::RenderWindow* window, GameDirector* game, IGameObject* player);
	MenuScreen();
	~MenuScreen();

	sf::RenderWindow* Window;
	GameDirector* Game;
	IGameObject* Player;
	Rectangle MapSize;

	GhostRectangle* playButton;
	GhostRectangle* exitButton;
	GhostRectangle* selector;

	enum MenuOptions { Play = 0, Exit = 1 };
	MenuOptions Option;

	IMap* CurrentMap;
	bool ChangeMap = false;
	bool ExitMap = false;

	void Initialize(sf::RenderWindow* window, GameDirector* game, IGameObject* player, IMap* currentMap) override;
	void Load() override;
	IMap* GetMap() override;
	bool GetExit() override;
	bool GetChange() override;
	void Upkeep() override;
};