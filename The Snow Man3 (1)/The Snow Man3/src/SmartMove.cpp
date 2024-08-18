#include "SmartMove.h"
#include "MovingObject.h"
#include <iostream>
void SmartMove::moveObject(MovingObject& obj) {

	auto distance = sf::Vector2f(obj.getPrevDirection().x - obj.getSprite().getPosition().x , obj.getPrevDirection().y - obj.getSprite().getPosition().y);

	if (distance.x > 0 && distance.x > MAXIMUM_SPEED)
		distance.x = MAXIMUM_SPEED;

	else if (distance.x < 0 && distance.x < -MAXIMUM_SPEED)
		distance.x = -MAXIMUM_SPEED;

	if (distance.y > 0 && distance.y > MAXIMUM_SPEED)
		distance.y = MAXIMUM_SPEED;

	else if (distance.y < 0 && distance.y < -MAXIMUM_SPEED)
		distance.y = -MAXIMUM_SPEED;

	obj.moveSprite(distance);

}