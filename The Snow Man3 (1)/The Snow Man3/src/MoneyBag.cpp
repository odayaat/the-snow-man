#include "MoneyBag.h"
#include <iostream>
MoneyBag::MoneyBag()
//===============Constructor==============
{
	m_sprite.setTexture(*SingeltonTexture::instance().
		getTexture(CHARACTER, MONEY_BAG_TEXTURE));

}

