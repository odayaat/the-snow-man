#pragma once
#include "StaticObject.h"
#include "SingeltonTexture.h"
class Tree : public StaticObject
{
public:

	//===========Constructor=============
	Tree();

	//===============Destractor==========
	~Tree() = default;

private:
	static bool m_registerit; // for factory
};
