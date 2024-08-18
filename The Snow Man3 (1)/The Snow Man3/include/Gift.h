#pragma once
#include "SingeltonTexture.h"
#include "Animation.h"
#include "StaticObject.h"
class Gift : public StaticObject
{
public:

	//===========Constructor=============
	Gift();

	//===========getter mathods==========
	int getNumber() const;

private:
	int m_addScore;
	static bool m_registerit;// for factory
};

