#pragma once
#include "SingeltonTexture.h"
#include "Animation.h"
#include "StaticObject.h"
class Coin : public StaticObject
{
public:
	//=================virtual functions==============
	void draw(sf::RenderWindow& window) override;

	//===========Constructor=============
	Coin();


private:
	Animation m_coinAnim;
	static bool m_registerit;// for factory
};

