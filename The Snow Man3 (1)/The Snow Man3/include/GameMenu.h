#pragma once
#include "Command.h"
#include "SingeltonSound.h"


class GameMenu {

public:
	void draw(sf::RenderWindow&) const;
	void addNewButton(std::string name, std::unique_ptr<Command> , sf::Vector2i );
	~GameMenu() = default;
	GameMenu(const sf::Texture&);
	int getTheOperationChosen(sf::Event , sf::RenderWindow& ) const;
	void activate(sf::RenderWindow&);
	bool performAction(const int& , sf::RenderWindow& ) const;


private:

	sf::Text m_textTitle;
	sf::Sprite m_background;
	typedef std::pair<std::string, std::unique_ptr<Command>> option;
	std::vector<option> m_options;
	
};
