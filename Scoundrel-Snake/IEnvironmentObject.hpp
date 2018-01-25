#pragma once
#include "IObject.hpp"
#include <exception>
#include <string>

class IEnvironmentObject : public IObject
{
	/* An environment object is an object that is tangible within the game,
	*  but is not an "active" element - as in it does not need to actively check
	*  collisions with other objects, instead, other objects need to check collision
	*  with it.  */
public:
	//bool operator==(const IEnvironmentObject& lhs)
	//{
	//	try
	//	{
	//		(IEnvironmentObject)lhs;
	//	}
	//	catch (std::exception&)
	//	{
	//		return false;
	//	}
	//	return true;
	//}
	virtual void Dispose() { throw new std::string("Virtual method 'Dispose()' not overridden."); };

	IEnvironmentObject() {};
	virtual ~IEnvironmentObject() {};
};
