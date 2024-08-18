#include "Hole.h"

Hole::Hole()
//===============Constructor================
{
	m_holeAnim = Animation(sf::Vector2i(13, 1), 0.24, *SingeltonTexture::instance().getTexture(CHARACTER, HOLE_ANIMATION_TEXTURE));//initialize the animation
	m_sprite.setTexture(*SingeltonTexture::instance().getTexture(CHARACTER, HOLE_ANIMATION_TEXTURE));
	m_sprite.setTextureRect(*m_holeAnim.get_uvRect());

}

void Hole::draw(sf::RenderWindow& window)
//===============draw================
{

	m_holeAnim.updateAnimation(0, 0.0015);//calculates the right animation
	m_sprite.setTextureRect(*m_holeAnim.get_uvRect());//sets the correct texture
	window.draw(m_sprite);
}