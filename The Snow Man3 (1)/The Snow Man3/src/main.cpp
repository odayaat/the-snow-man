#include <iostream>
#include "StartGame.h"
#include "QuitGame.h"
#include "GameMenu.h"
#include "FactoryObjects.h"
#include "SingeltonTexture.h"
#include "InfoGame.h"
int main()
{
	try
	{
		std::srand(std::time(NULL));
		sf::RenderWindow window(sf::VideoMode(1550, 800, 32), "The Snow Man", sf::Style::Close);
		SingeltonSound::instance().playMusic(MENU_MUSIC);
		GameMenu gameMenu(*SingeltonTexture::instance().getTexture(BACKGROUND,MENU_BACKGROUND));
		gameMenu.addNewButton("Start", std::make_unique<StartGame>(), START_BUTTON_LOCATION);
		gameMenu.addNewButton("Quit", std::make_unique<QuitGame>(), QUIT_BUTTON_LOCATION);
		gameMenu.addNewButton("Info", std::make_unique<InfoGame>(), INFO_BUTTON_LOCATION);
		gameMenu.draw(window);
		gameMenu.activate(window);
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}
}
