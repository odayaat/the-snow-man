#pragma once
#include "Board.h"

class Controller
{
public:

	//===========Constructor=============
	Controller();
	
	//==========Destructor=============
	~Controller() = default;

	void createBoard();
	void handleGameEvents(sf::RenderWindow&);
	sf::Vector2i getDir();
	void displayTheScore(sf::RenderWindow& window);
	void runGame(sf::RenderWindow&);

	//============setter methods===========
	void setView(sf::RenderWindow&);
	
private:
	Board m_board;
	sf::Sprite m_gameOverBackground;
	sf::Text m_scoreText;
};

