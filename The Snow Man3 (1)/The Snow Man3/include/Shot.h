#pragma once
#include "MovingObject.h"
#include "SingeltonTexture.h"
#include "StriteMove.h"
class Shot :public MovingObject
{
public:
	Shot();
	~Shot() = default;
	void virtual move(const float& time)override;
private:

	static bool m_registerit; // for factory
};
