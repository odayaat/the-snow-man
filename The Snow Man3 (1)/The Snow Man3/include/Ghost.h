#pragma once

#include "Animation.h"
#include "SingeltonTexture.h"
#include "MovingObject.h"
#include "SmartMove.h"

class Ghost : public MovingObject
{
public:

	//==============virtual functions============
	virtual void move(const float&) override;

	//===============Constructor===========
	Ghost();

	//===========Destructor============
	~Ghost() = default;

private:
	Animation m_ghostAnim;
	static bool m_registerit;
	sf::Vector2f m_target;
};

