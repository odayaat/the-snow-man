#include "SingeltonFont.h"

const sf::Font* SingeltonFont::getFontGame(const int& num) const 
//=============getFontGame==============
{
	if(num < FONTS)
		return &m_fonts[num];
	return &m_fonts[FONTS - 1];//default
}
SingeltonFont::SingeltonFont() 
//===========Constructor===============
{
	m_fonts[INFORMATION_FONT].loadFromFile("Information.ttf");
	m_fonts[SUPER_MARIO_FONT].loadFromFile("SuperMario256.ttf");
	
}
SingeltonFont& SingeltonFont::instance() 
//===========Singelton===============
{
	static SingeltonFont inst;
	return inst;
}