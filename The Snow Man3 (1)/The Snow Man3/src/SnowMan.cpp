#include "SnowMan.h"
SnowMan::SnowMan()
{

	int texture = rand() % 2;
	if (texture == 0)//create two diffrents sonwmen
	{
		m_sprite.setTexture(*SingeltonTexture::instance().
			getTexture(CHARACTER, SNOW_MAN_ONE_TEXTURE));
	}
	else {
		m_sprite.setTexture(*SingeltonTexture::instance().
			getTexture(CHARACTER, SNOW_MAN_TWO_TEXTURE));
	}

}

