#include "Brick.h"
Brick::Brick()
//===============Constructor==============
{
	m_sprite.setTexture(*SingeltonTexture::instance().
					getTexture(CHARACTER, BRICK_TEXTURE));
}

