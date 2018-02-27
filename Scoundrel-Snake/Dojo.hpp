#pragma once
#include "IMap.hpp"
#include "../Utility/Geometry.hpp"

class Dojo : public IMap
{
public:
	Dojo(sf::RenderWindow* window, GameDirector* game, IGameObject* player);
	~Dojo();

	sf::RenderWindow* Window;
	GameDirector* Game;
	IGameObject* Player;
	Rectangle MapSize;

	void Load() override;
	void Upkeep() override;
};