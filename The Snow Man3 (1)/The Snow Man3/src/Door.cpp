#include "Door.h"
Door::Door()
//===============Constructor==============
{
	m_sprite.setTexture(*SingeltonTexture::instance().
		getTexture(CHARACTER, DOOR_TEXTURE));
}
