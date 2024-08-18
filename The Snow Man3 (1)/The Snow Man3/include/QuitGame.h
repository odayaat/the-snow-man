#pragma once
#include "Command.h"
class QuitGame :public Command
{
public:
	//=============virtual functions========
	bool executeTask(sf::RenderWindow& window) override;
	virtual ~QuitGame() = default;

	//=========Constructor================
	QuitGame();

private:

};


