#include "GameObject.h"

void GameObject::setDead() 
{
//===============setDead=================
	m_isDead = true;
}
void GameObject::draw(sf::RenderWindow& window) 
{
//================draw=============

	window.draw(m_sprite);

}

void GameObject::moveSprite(const sf::Vector2f& dir) {
	m_sprite.move(dir);
}
bool GameObject::isDead() const 
//==========isDead===============
{
	return m_isDead;
}


void GameObject::setSpriteLocation(const sf::Vector2f& location) 
{
//===========setSpriteLocation============
	m_sprite.setPosition(location);
}

const sf::Sprite& GameObject::getSprite() const 
{
//===========getSprite============
	return m_sprite;
}
