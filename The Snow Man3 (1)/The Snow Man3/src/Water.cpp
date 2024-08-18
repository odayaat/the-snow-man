#include "Water.h"
Water::Water()
{

	m_sprite.setTexture(*SingeltonTexture::instance().
		getTexture(CHARACTER, WATER_TEXTURE));

}
