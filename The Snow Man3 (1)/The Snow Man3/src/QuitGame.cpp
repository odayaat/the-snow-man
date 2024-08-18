#include "QuitGame.h"
#include <windows.h>

bool QuitGame::executeTask(sf::RenderWindow& window) 
//==============executeTask==========
//The functions draws quit background and sleeps X seconds before finishing
{

    window.clear();
    window.draw(m_backGround);
    window.display();
    Sleep(THREE_SECONDS);
	exit(EXIT_SUCCESS);
}
QuitGame::QuitGame()
{
    m_backGround.setTexture(*SingeltonTexture::instance().getTexture(BACKGROUND, QUIT_BACKGROUND));
}
