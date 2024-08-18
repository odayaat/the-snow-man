#pragma once
#include "SingeltonTexture.h"
#include "Animation.h"
#include "StaticObject.h"
class Hole : public StaticObject
{
public:
	//=============virtual functions========
	void virtual draw(sf::RenderWindow& window) override;

	//=========Constructor================
	Hole();
	//=========Destractor================
	~Hole() = default;

private:
	Animation m_holeAnim;
	static bool m_registerit;
};

