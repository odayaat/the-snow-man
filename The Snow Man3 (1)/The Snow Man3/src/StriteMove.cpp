#include "StriteMove.h"
#include "MovingObject.h"
void StriteMove::moveObject( MovingObject& obj)  {

	obj.moveSprite(sf::Vector2f(obj.getPrevDirection().x * obj.getSpeed(), obj.getPrevDirection().y * obj.getSpeed()));

}