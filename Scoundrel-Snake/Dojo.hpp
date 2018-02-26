#pragma once
#include "IMap.hpp"

class Dojo : public IMap
{
public:
	Dojo(sf::RenderWindow* window, GameDirector* game);
	~Dojo();

	sf::RenderWindow* Window;
	GameDirector* Game;

	void Load() override;
	void Upkeep() override;
};