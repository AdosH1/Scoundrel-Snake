#pragma once
#include "IMap.hpp"
#include "../Utility/Geometry.hpp"

class Dojo : public IMap
{
public:
	/*Dojo(sf::RenderWindow* window, GameDirector* game, IGameObject* player);*/
	Dojo();
	~Dojo();

	sf::RenderWindow* Window;
	GameDirector* Game;
	IGameObject* Player;
	Rectangle MapSize;
	IMap* CurrentMap;
	bool ChangeMap = false;
	bool ExitMap = false;
	int RatsCreated = 0;

	void Initialize(sf::RenderWindow* window, GameDirector* game, IGameObject* player, IMap* currentMap) override;
	void Load() override;
	bool GetChange() override;
	IMap* GetMap() override;
	bool GetExit() override;
	void Upkeep() override;
};