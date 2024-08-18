#pragma once
#include "SingeltonTexture.h"
#include "StaticObject.h"
class Bullet : public StaticObject
{
public:
	//===========Constructor=============
	Bullet();

	//=========Destractor================
	~Bullet() = default;

private:
	static bool m_registerit;// for factory
};
