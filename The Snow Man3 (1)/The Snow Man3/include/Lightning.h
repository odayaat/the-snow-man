
#pragma once
#include "StaticObject.h"
#include "SingeltonTexture.h"
class Lightning : public StaticObject
{
public:
	//=========Constructor================
	Lightning();

	//=========Destractor================
	~Lightning() = default;

private:
	static bool m_registerit;//for factory
};
