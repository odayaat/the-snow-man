#include "Coin.h"

Coin::Coin()
//============Constructor================
{
	m_coinAnim = Animation(sf::Vector2i(8, 1), 0.23, *SingeltonTexture::instance().getTexture(CHARACTER, COIN_ANIMATION_TEXTURE));//initialize the animation
	m_sprite.setTexture(*SingeltonTexture::instance().getTexture(CHARACTER, COIN_ANIMATION_TEXTURE));
	m_sprite.setTextureRect(*m_coinAnim.get_uvRect());
}

void Coin::draw(sf::RenderWindow& window) 
//============draw================
{

	m_coinAnim.updateAnimation(0, 0.009);//calculates the right animation
	m_sprite.setTextureRect(*m_coinAnim.get_uvRect());//sets the correct texture
	window.draw(m_sprite);
}