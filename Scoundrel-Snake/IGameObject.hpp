#pragma once
#include "IObject.hpp"
#include "../Utility/Point.hpp"
#include <deque>

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

	virtual Point GetPosition() { throw std::exception("GetPosition method not implemented."); };
	virtual std::deque<Point> GetPositionList() { throw std::exception("GetPositionList method not implemented."); }
	virtual Point GetLastPosition() { throw std::exception("GetLastPosition method not implemented."); };
	virtual double GetSpeed() { throw std::exception("GetSpeed method not implemented."); };

	virtual bool SetPosition(Point pos) { throw std::exception("SetPosition method not implemented."); };
	virtual bool SetLastPosition(Point pos) { throw std::exception("SetLastPosition method not implemented."); };
	virtual bool SetSpeed(double speed) { throw std::exception("SetSpeed method not implemented."); };

	virtual bool Update(int input = NULL) { throw std::exception("Update method not implemented."); };
};
