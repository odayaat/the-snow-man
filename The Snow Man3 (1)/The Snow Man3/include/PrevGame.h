#pragma once
#pragma once
#include "Command.h"
class PrevGame :public Command
{


public:

	//=============virtual functions========
	bool virtual executeTask(sf::RenderWindow& window) override;
	PrevGame() = default;
	~PrevGame() = default;

private:

};


