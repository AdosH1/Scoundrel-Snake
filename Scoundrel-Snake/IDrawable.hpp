#pragma once
#include "IObject.hpp"

class IDrawable : public virtual IObject
{
	/* This interface is meant to be inherited by objects that are able to be drawn.
	 * The GameDirector will hold a list of drawables that will be queued to draw per frame. */
public:
	/*bool operator==(const IDrawable& lhs)
	{
		try
		{
			(IDrawable)lhs;
		}
		catch (std::exception&)
		{
			return false;
		}
		return true;
	}*/
	virtual void Draw()
	{
		/* I don't believe the compiler accepts non-overriden virtual functions,
		 * so this should never trigger. Regardless...  */
		throw new std::string("Virtual function 'Draw()' not overridden.");
	};
	virtual ~IDrawable() {};
};
