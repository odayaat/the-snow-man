#pragma once
#include "Command.h"
class InfoGame :public Command
{


public:

	//=============virtual functions========
	bool virtual executeTask(sf::RenderWindow& window) override;
	InfoGame();
	~InfoGame() = default;

private:

};


