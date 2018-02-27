#pragma once
#include "IObject.hpp"
#include "../Utility/Point.hpp"

class IGameObject : public virtual IObject
{
	/* A game object is an object that is tangible within the game.
	 * The GameDirector will keep track of all game objects in play. */
public:
	bool operator==(const IGameObject& lhs)
	{
		try
		{
			(IGameObject)lhs;
		}
		catch (std::exception&)
		{
			return false;
		}
		return true;
	}

	IGameObject() {};
	virtual ~IGameObject() {};

	virtual Point Position() { return Point(); };
};
