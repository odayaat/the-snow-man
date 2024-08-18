#pragma once
#include <fstream>
#include "Const.h"
#include "SingeltonTexture.h"
#include "Player.h"
#include "Brick.h"
#include "Tree.h"
#include "StartFlag.h"
#include "Enemy.h"
#include "SnowMan.h"
#include "Bullet.h"
#include "Hole.h"
#include "Lightning.h"
#include "SingeltonFont.h"
#include "Coin.h"
#include "Door.h"
#include "Ghost.h"
#include "Gift.h"
class Board
{
public:

	//=================getter method==================
	int getScore() const;

	//===========Constructor=============
	Board();


	//=========Destractor================
	~Board() = default;


	//=========setter method================
	void setBoardPostion(const float x);
	void setScoreToPlayer();

	void shotRcoket(const char& c);
	void shotBullet(const char& c);
	void moveAutoObjects(const float&);
	bool playerDidwin();
	void saveScore();
	void deleteDeadObjects();
	const sf::Vector2f* getLocationOfPlayer() const;
	bool isHappenedCollision(const GameObject&, const GameObject&);
	void drawInformaionGame(sf::RenderWindow& window);
	void createObject(char, sf::Vector2f);
	void readBoard();
	void move(const sf::Vector2i&,const float);
	void drawBoard(sf::RenderWindow&);
	void handleCollision();
	bool isGameOver() const;
	void saveBoard();

private:

	bool m_gameOver = false;
	void setSettingTexture(sf::Text &);
	std::unique_ptr<MovingObject> m_player;//save my player
	std::vector<std::unique_ptr<StaticObject>> m_staticObject;//all the static objects
	std::vector<std::unique_ptr<MovingObject>> m_movingObject;//all the auto moving objects
	
	sf::Sprite m_background,m_bullet,m_coins;
	sf::Text m_bulletText, m_coinsText, m_scoreText;
	std::fstream m_file;
	int m_lastScore = 0;
	void openFile();//open the file of map
};
