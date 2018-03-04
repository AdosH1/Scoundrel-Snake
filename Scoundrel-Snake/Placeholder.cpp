#include "Placeholder.hpp"

Placeholder::Placeholder()
{
	
}

Placeholder::~Placeholder()
{
	
}

Point Placeholder::GetPosition()
{
	return Point(0, 0);
}

Point Placeholder::GetLastPosition()
{
	return Point(0, 0);
}

double Placeholder::GetSpeed()
{
	return 0;
}

bool Placeholder::GetDispose()
{
	return Dispose;
}

bool Placeholder::SetPosition(Point pos)
{
	return false;
}

bool Placeholder::SetLastPosition(Point pos)
{
	return false;
}

bool Placeholder::SetSpeed(double speed)
{
	return false;
}

bool Placeholder::SetDispose(bool dispose)
{
	Dispose = dispose;
	return true;
}

bool Placeholder::Update(int input)
{
	return false;
}










