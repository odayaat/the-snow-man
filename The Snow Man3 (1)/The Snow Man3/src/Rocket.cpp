#include "Rocket.h"
#include <iostream>

Rocket::Rocket() {

	m_sprite.setTexture(*SingeltonTexture::instance().
		getTexture(CHARACTER, BULLET_TEXTURE));

	m_rocketAnim = Animation(sf::Vector2i(8, 1), 0.25, *SingeltonTexture::instance().getTexture(CHARACTER, ROCKET_ANIMATION_TEXTURE));//initialize the animation
	m_sprite.setTexture(*SingeltonTexture::instance().getTexture(CHARACTER, ROCKET_ANIMATION_TEXTURE));
	m_sprite.setScale(1.2, 1.2);
	m_sprite.setTextureRect(*m_rocketAnim.get_uvRect());

	m_moveBehavior = std::make_unique<StriteMove>();
}

void Rocket::move(const float& time) {

	m_rocketAnim.updateAnimation(0, time);//calculates the right animation
	m_sprite.setTextureRect(*m_rocketAnim.get_uvRect());//sets the correct texture
	m_speed = SHOT_SPEED * time;
	m_moveBehavior->moveObject(*this);

}
void  Rocket::setPrevDirection(const sf::Vector2f dir) {

	m_prevDirection = dir;

	if (m_prevDirection.x != 0 && m_prevDirection.x < 0) {
		m_sprite.setRotation(180);
		m_sprite.move(0, 55);

	}
	else if (m_prevDirection.y > 0) {
		m_sprite.setRotation(90);
		m_sprite.move(50, 0);
	}
	
	else if (m_prevDirection.y < 0) {
		m_sprite.setRotation(-90);
		m_sprite.move(-3, 0);
	}

}
