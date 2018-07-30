#pragma once

class IObject
{
	/* Generic object used for ambiguious object calls */
public:
	IObject() {};
	virtual ~IObject() {};

	virtual bool GetDispose() { return false;/*throw std::exception("GetDispose method not implemented.");*/ }
	virtual bool SetDispose(bool dispose = false) { return false;/*throw std::exception("GetDispose method not implemented.");*/ }
};