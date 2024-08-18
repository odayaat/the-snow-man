#include "Gift.h"
#include <iostream>
Gift::Gift()
//===============Constructor==============
{
	int score;
	do {// stes the value of gift (between -10 to 11)

		score = rand() % 22-10;
	} while (score == 0);
	m_addScore = score;
	m_sprite.setTexture(*SingeltonTexture::instance().
		getTexture(CHARACTER, GIFT_TEXTURE));

}
int Gift::getNumber() const{
	return m_addScore;
}
