#pragma once
#include "StaticObject.h"
#include "SingeltonTexture.h"
class SnowMan : public StaticObject
{
public:
	//===========Constructor=============
	SnowMan();

	//===============Destractor==========
	~SnowMan() = default;

private:
	static bool m_registerit;//for factory
};

