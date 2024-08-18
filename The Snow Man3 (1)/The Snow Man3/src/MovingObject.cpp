#include "MovingObject.h"

sf::Vector2f MovingObject::getPrevDirection() const{
	return m_prevDirection;
}
void MovingObject::setPrevDirection(const sf::Vector2f  dir)  {
	m_prevDirection = dir;
}
float MovingObject::getSpeed() {
	return m_speed;
}