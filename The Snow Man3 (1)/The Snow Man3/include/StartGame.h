#pragma once
#include "Command.h"
#include "Animation.h"
class StartGame : public Command
{

public:

	//=============virtual functions========
	bool virtual executeTask(sf::RenderWindow& window) override;
	virtual ~StartGame() = default;

	//===========Constructor=============
	StartGame();
 

private:
	sf::Sprite m_spriteAnimation;
	Animation m_loadingAnimation;
};

