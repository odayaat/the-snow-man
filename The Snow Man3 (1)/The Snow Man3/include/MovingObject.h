#pragma once
#include "GameObject.h"
#include "MoveBehavior.h"
#include "Const.h"
class MovingObject : public GameObject
{
public:
	float getSpeed();
	MovingObject() = default;
	 ~MovingObject()  =default;
	sf::Vector2f getPrevDirection() const;
	void virtual setPrevDirection(const sf::Vector2f );
	void virtual move(const float& time) {
		m_moveBehavior->moveObject(*this);
	}


protected:
	std::unique_ptr<MoveBehavior> m_moveBehavior;
	float m_speed;
	sf::Vector2f m_prevDirection = sf::Vector2f(0, 50);
};
