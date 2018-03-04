#pragma once
#include "GhostRectangle.hpp"
#include "Wall.hpp"
#include "GameDirector.hpp"
#include "GraphicsFactory.hpp"

class IMap
{
public:
	IMap() {};
	virtual ~IMap(){};

	virtual bool GetChange() { return false; };
	virtual bool GetExit() { return false; }
	virtual IMap* GetMap()
	{
		IMap* map = new IMap();
		return map;
	};

	virtual void Initialize(sf::RenderWindow* window, GameDirector* game, IGameObject* player, IMap* currentMap) {};
	virtual void Load(){};
	virtual void Upkeep(){};
};