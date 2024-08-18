#pragma once
#include "MovingObject.h"
#include "SingeltonTexture.h"
#include "StriteMove.h"
#include "Animation.h"
class Rocket :public MovingObject
{
public:
	Rocket();
	~Rocket() = default;
	void virtual move(const float& time)override;
	void virtual setPrevDirection(const sf::Vector2f) override;
private:
	Animation m_rocketAnim;
	static bool m_registerit; // for factory
};
