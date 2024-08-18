#include "StartFlag.h"
StartFlag::StartFlag(){

	m_sprite.setTexture(*SingeltonTexture::instance().
		getTexture(CHARACTER, START_FALG_TEXTURE));
}