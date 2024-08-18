#pragma once
#include "StaticObject.h"
#include "SingeltonTexture.h"
class Water : public StaticObject
{
public:

	//===========Constructor=============
	Water();

	//===============Destractor==========
	~Water() = default;

private:
	static bool m_registerit; // for factory
};
