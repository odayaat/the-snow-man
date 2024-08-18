#pragma once
#include "Const.h"
#include <string>
#include "SingeltonTexture.h"
#include "SingeltonFont.h"
class Command {

public:


	//=================virtual functions==============
	virtual bool executeTask(sf::RenderWindow& window) = 0;
	virtual ~Command() = default;
	//===========Constructor=============
	Command();

	//==============setter method==============
	void setText(std::string name, sf::Vector2i pos);

	//==============getter method==============
	const sf::Text& getText() const;

protected:
	sf::Sprite m_backGround;
private:
	sf::Text m_text;

};
