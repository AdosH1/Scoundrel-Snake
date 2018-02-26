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

	virtual void Load(){};
	virtual void Upkeep(){};
};