#include "Command.h"


void Command::setText( std::string name,  sf::Vector2i pos) 
//============setText===============
//The funcction set the name of button and postion of button
{
	m_text.setString(name);
	m_text.setPosition(pos.x, pos.y);
}

const sf::Text& Command::getText() const 
//=========getText=================
{

	return m_text;

}
Command::Command()
//=============Constructor============
{

	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(55);
	m_text.setFont(*SingeltonFont::instance().getFontGame(INFORMATION_FONT));//loads font
}
