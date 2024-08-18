#pragma once
#include "Const.h"
class SingeltonFont
{
public:


	static SingeltonFont& instance();
	~SingeltonFont() = default;
	const sf::Font* getFontGame(const int& num) const;

private:

	sf::Font m_fonts[FONTS];
	SingeltonFont(const SingeltonFont&) = default;
	SingeltonFont& operator=(const SingeltonFont&) = default;
	SingeltonFont();
};
