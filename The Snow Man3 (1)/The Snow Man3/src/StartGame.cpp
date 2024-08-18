#include "StartGame.h"
#include "Controller.h"
#include "SingeltonSound.h"
#include <windows.h>
#include <iostream>

bool StartGame::executeTask(sf::RenderWindow& window) 
//============executeTask===================
//virtual function that creates the loading animation and starts the game
{
	sf::Clock time;
	float timeThatWasPassed = 0.0f;//for animation
	Controller game;

	SingeltonSound::instance().pauseMusic(MENU_MUSIC);
	while (timeThatWasPassed < 13 * 0.30)//until all animation will be presented
	{
		float temp = time.restart().asSeconds();
		timeThatWasPassed += temp;
		window.clear();
		window.draw(m_backGround);
		m_loadingAnimation.updateAnimation(0, temp);
		m_spriteAnimation.setTextureRect(*m_loadingAnimation.get_uvRect());//sets the correct texture
		window.draw(m_spriteAnimation);
		window.display();
		
	}

	SingeltonSound::instance().playMusic(GAME_MUSIC);
	game.runGame(window);							         //starts game 
	window.setView(sf::View(sf::FloatRect(0, 0, WIDTH, HEIGHT)));//focus to start 
	SingeltonSound::instance().playMusic(MENU_MUSIC);
	SingeltonSound::instance().pauseMusic(GAME_MUSIC);
	return true;// true for staying in menu
}

StartGame::StartGame(){
//===============constructor==================
	m_loadingAnimation  = Animation(sf::Vector2i(13,1), 0.30, *SingeltonTexture::instance().getTexture(CHARACTER, LOADING_ANIMATION_TEXTURE));//initialize the animation
	m_spriteAnimation.setTexture(*SingeltonTexture::instance().getTexture(CHARACTER, LOADING_ANIMATION_TEXTURE));
	m_spriteAnimation.setPosition(sf::Vector2f(WIDTH/2 -80,HEIGHT / 2 -40));
	m_spriteAnimation.setScale(1.5, 1.5);
	m_spriteAnimation.setTextureRect(*m_loadingAnimation.get_uvRect());
	m_backGround.setTexture(*SingeltonTexture::instance().getTexture(BACKGROUND, START_BACKGROUND));

}