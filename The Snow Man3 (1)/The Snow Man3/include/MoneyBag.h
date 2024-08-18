#pragma once
#include "StaticObject.h"
#include "SingeltonTexture.h"
class MoneyBag : public StaticObject
{
public:

	//===========Constructor=============
	MoneyBag();

	//===============Destractor==========
	~MoneyBag() = default;

private:
	static bool m_registerit; // for factory
};
