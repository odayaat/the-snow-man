#pragma once
#include "StaticObject.h"
#include "SingeltonTexture.h"
class StartFlag : public StaticObject
{
public:

	//============Constructor============
	StartFlag();

	//===============Destractor==========
	~StartFlag() = default;

private:
	static bool m_registerit;//for factory
};

