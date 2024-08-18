#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Const.h"
class SingeltonTexture
{
public:
	
	static SingeltonTexture& instance();
	const sf::Texture* getTexture(const char&, const int&) const;//returns a texture by type

private:

	sf::Texture m_playersTexture[CHARACTERS_TEXTURE];//saves all the objects like player,brick...
	sf::Texture m_backgrondsTexture[BACKGROUNDS];//saves all the backgrounds
	
	//defult 
	SingeltonTexture();
	~SingeltonTexture() = default;
	SingeltonTexture(const SingeltonTexture&) = default;
	SingeltonTexture& operator=(const SingeltonTexture&) = default;

};
