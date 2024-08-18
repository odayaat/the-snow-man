#include "GameMenu.h"


GameMenu::GameMenu(const sf::Texture& backgroundMenu)
//==============Constructor===========
{
	m_background.setTexture(backgroundMenu);
}

void GameMenu::draw(sf::RenderWindow& window)const
//=================draw================
// The function draw all the options
{

	window.clear();
	window.draw(m_background);

	for (const auto& option : m_options)
		window.draw(option.second->getText());

	window.display();
}
void GameMenu::addNewButton(std::string name, std::unique_ptr<Command> c, sf::Vector2i pos)
//======addNewButton===========
//The function adds new buuton tot the menu
{

	m_options.emplace_back(option(name, move(c)));
	m_options[m_options.size() - 1].second->setText(name,pos);
}


bool GameMenu::performAction(const int & option , sf::RenderWindow& window) const
//=============performAction=============
//The function does the option that chosen(if is exists) and returns 
//true or false if after the operation the menu needs to closed or to continue
{

	bool temp;
	if (option != -2) {
		SingeltonSound::instance().doSoundEft(SELECT_EFT);
		temp = m_options[option].second->executeTask(window);
		draw(window);
		return temp;
	}
	return true;
}


int GameMenu::getTheOperationChosen(sf::Event event, sf::RenderWindow& window) const 
//=========getTheOperationChosen============
//the function returns the option that chosen, otherwise  returns - 2
{


	for (int i = 0; i < m_options.size(); i++) 
	{
		if (m_options[i].second->getText().getGlobalBounds().contains(window.mapPixelToCoords
		({ event.mouseButton.x,event.mouseButton.y }))) {
			return i;
		}
	}
		
			
	return -2;
}
void GameMenu::activate(sf::RenderWindow& window) 
//===============activate=============
//The function listens for user clicks and checks
//if it was a button, if it was the task will be executed
{

	sf::Event event;
	int option;

	while (true) {

		while (window.pollEvent(event)) 
		{

			if ((event.type == sf::Event::Closed)) 
			{
				window.close();
				exit(EXIT_SUCCESS);
			}

			if (sf::Event::MouseButtonPressed == event.type) 
			{
				option = getTheOperationChosen(event, window);
				if (!performAction(option, window))
					return;
			}

		}	
	}	
}


