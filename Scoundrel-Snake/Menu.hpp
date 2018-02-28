#pragma once
#include "IMap.hpp"
#include "GameDirector.hpp"
#include "PlayerControl.hpp"

class Menu : public IMap
{
public:
	Menu(sf::RenderWindow* window, GameDirector* game, IGameObject* player);
	~Menu();

	sf::RenderWindow* Window;
	GameDirector* Game;
	IGameObject* Player;
	Rectangle MapSize;

	void Load() override;
	void Upkeep() override;
};