#include "Bullet.h"
Bullet::Bullet()
//============Constructor===============
{
	m_sprite.setTexture(*SingeltonTexture::instance().
		getTexture(CHARACTER, BULLET_TEXTURE));
}
