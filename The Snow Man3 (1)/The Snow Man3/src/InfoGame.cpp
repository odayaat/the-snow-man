#include "infoGame.h"
#include "GameMenu.h"
#include "PrevGame.h"
bool  InfoGame::executeTask(sf::RenderWindow& window)  {

	GameMenu gameMenu(*SingeltonTexture::instance().getTexture(BACKGROUND, INFO_BACKGROUND));
	gameMenu.addNewButton("Prev", std::make_unique<PrevGame>(), PREV_BUTTON_LOCATION);
	gameMenu.draw(window);
	gameMenu.activate(window);

	return true;
}
InfoGame::InfoGame()
{
	
}