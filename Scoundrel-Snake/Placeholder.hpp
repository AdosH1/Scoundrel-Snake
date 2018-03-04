#pragma once

#include <deque>
#include "SFML/Graphics.hpp"
#include "GraphicsFactory.hpp"
#include "IDrawable.hpp"
#include "IGameObject.hpp"
#include "../Utility/Point.hpp"

class Placeholder : public IGameObject
{
public:
	/* Base Class Implementations*/
	Point GetPosition() override;
	Point GetLastPosition() override;
	double GetSpeed() override;
	bool GetDispose() override;

	bool SetPosition(Point pos) override;
	bool SetLastPosition(Point pos) override;
	bool SetSpeed(double speed) override;
	bool SetDispose(bool dispose) override;

	bool Update(int input) override;

	bool Dispose = false;

	/* Constructors / Destructors */
	Placeholder();
	~Placeholder();
};

