#include "Shot.h"
#include <iostream>

Shot::Shot() {
	m_sprite.setTexture(*SingeltonTexture::instance().
		getTexture(CHARACTER, BULLET_TEXTURE));

	m_moveBehavior = std::make_unique<StriteMove>();
}

void Shot::move(const float& time) {

	m_speed = SHOT_SPEED * time;
	m_moveBehavior->moveObject(*this);
	
}
