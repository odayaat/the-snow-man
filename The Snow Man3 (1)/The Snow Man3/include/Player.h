#pragma once
#include "Animation.h"
#include "SingeltonTexture.h"
#include "MovingObject.h"
#include "StriteMove.h"
class Player: public MovingObject
{
public:
	//=============virtual functions========
	virtual void move(const float &timeThatWasPassed) override;

	//=======setter methods=============
	void setBullet(const int&);
	void setScore(const int&);
	void setCoin(const int&);
	void setRocket(const int& num);
	
	//=======getter methods=============
	int getScore() const;
	int getCoin() const;
	int getBullet() const;
	int getRocket() const;

	void moveBack();
	void extraSpeed();

	//=========Constructor================
	Player();

	//=========Destractor================
	~Player() = default;

private:
	static bool m_registerit;//for factory
	int m_rocket = 1;
	int m_bullet = 10;
	int m_coins = 0;
	int m_score = 0;
	double m_extraSpeedPlayer = 0;// speed player
	Animation m_playerAnim;
	
};
