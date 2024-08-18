#pragma once
#include "SingeltonTexture.h"
#include "Animation.h"
#include "StaticObject.h"
class Door : public StaticObject
{
public:

	//===============Constructor==============
	Door();

	//===============Destructor==============
	~Door() = default;

private:
	static bool m_registerit;
};

