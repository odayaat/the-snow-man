#include "Lightning.h"
Lightning::Lightning()
//===============Constructor==============
{
	m_sprite.setTexture(*SingeltonTexture::instance().
		getTexture(CHARACTER, LIGHTNING_TEXTURE));
}
