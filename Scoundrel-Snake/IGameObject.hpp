#pragma once
#include "IObject.hpp"

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
	virtual void Dispose() { throw new std::string("Virtual method 'Dispose()' not overridden."); };

	IGameObject() {};
	virtual ~IGameObject() {};
};
