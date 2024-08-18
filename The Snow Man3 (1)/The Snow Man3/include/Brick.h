#pragma once
#include "StaticObject.h"
#include "SingeltonTexture.h"

class Brick :public StaticObject 
{
public:
	//===========Constructor=============
	Brick ();

	//=========Destractor================
	~Brick () = default;

private:
	static bool m_registerit;
};

