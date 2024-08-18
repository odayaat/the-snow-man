#include "Board.h"
#include "CollisionHandling.h"
#include "MyFactory.h"
#include "SingeltonSound.h"
void Board::readBoard() 
//=============createBoard=============
//The function passes on the Board.txt file and creates all the objects(player,brick..)
{
	//clears all the objects
	m_movingObject.clear();
	m_staticObject.clear();
	m_player.reset();

	//reads map
	for (int row = 0; row < ROW_MAP-1; row++)
	{
		char charachter;
		if(row != 0)
			charachter = m_file.get();//eats the ENTER

		for (int col = 0; col < COL_MAP; col++)
		{
			charachter = m_file.get();
			if (charachter == GAME_OVER) {
				m_gameOver = true;
				return;
			}
				
			//calculates the location of object
			auto location = sf::Vector2f(SIZE_OF_BRICK + col * SIZE_OF_BRICK- SIZE_OF_BRICK, row * SIZE_OF_BRICK);
			if(charachter != ' ')
				createObject(charachter, location);
		}
	}
	char charachter = m_file.get();

}
bool Board::isGameOver() const
//============isGameOver============
{
	return m_gameOver;
}
void Board::handleCollision() 
//============handleCollision============
{

	//Between m_movingObject to  m_movingObject
	for (int i = 0; i < m_movingObject.size(); i++) 
		for (int j = 0; j < m_movingObject.size(); j++)
			if( i != j && isHappenedCollision(*m_movingObject[j], *m_movingObject[i]))
				processCollision(*m_movingObject[j], *m_movingObject[i]);

	//Between staticObject to  m_movingObject
	for (int i = 0; i < m_staticObject.size(); i++) {
		for (int j = 0; j < m_movingObject.size(); j++)
		{
			if (isHappenedCollision(*m_movingObject[j], *m_staticObject[i]))
				processCollision(*m_movingObject[j], *m_staticObject[i]);
		}
		//Between player to staticObject
		if (isHappenedCollision(*m_player, *m_staticObject[i]))
			processCollision(*m_player, *m_staticObject[i]);
	}

	//between player to m_movingObject
	for (int j = 0; j < m_movingObject.size(); j++)
		{
			if (isHappenedCollision(*m_player, *m_movingObject[j]))
				processCollision(*m_player ,*m_movingObject[j]);
		}


	//checks if the player died
	if (m_player->isDead()) {
		saveScore();
		m_file.seekg(-((ROW_MAP-1) * (COL_MAP+2)), std::ios::cur);
		readBoard();
	}

	//checks if the player won
	if (playerDidwin()) {
		saveScore();
		readBoard();
		return;
	}
	//clears the vectors of dead objects
	deleteDeadObjects();

}
void Board::saveScore() 
//========saveScore==========
//The function saves the last score of player 
{

	Player* myPlayer;
	myPlayer = dynamic_cast<Player*>(m_player.get());
	m_lastScore = myPlayer->getScore();

}


void Board::shotRcoket(const char& c)
//=========shutRcoket============
{
	Player* myPlayer;
	myPlayer = dynamic_cast<Player*>(m_player.get());
	
	if (myPlayer->getRocket() > 0) {
		myPlayer->setRocket(myPlayer->getRocket() - 1);
	
		m_movingObject.emplace_back(MyFactory<MovingObject>::createObject(c));
		m_movingObject[m_movingObject.size() - 1]->setSpriteLocation(*getLocationOfPlayer());
		m_movingObject[m_movingObject.size() - 1]->setPrevDirection(myPlayer->getPrevDirection());
	}
}

void Board::shotBullet(const char & c)
//=========shutBullet============
{
	Player* myPlayer;
	myPlayer = dynamic_cast<Player*>(m_player.get());
	static int clickes = 0;
	clickes++;
	if (clickes > 22 && myPlayer->getBullet() > 0) {
		myPlayer->setBullet(myPlayer->getBullet() - 1);
		clickes = 0;
		SingeltonSound::instance().doSoundEft(SHOT_EFT);
		m_movingObject.emplace_back(MyFactory<MovingObject>::createObject(c));
		m_movingObject[m_movingObject.size() - 1]->setSpriteLocation(*getLocationOfPlayer());
		m_movingObject[m_movingObject.size() - 1]->setPrevDirection(myPlayer->getPrevDirection());
	}

}
void Board::setScoreToPlayer()
//==========setScoreToPlayer========
//The function set the player score by dynamic cast
{

	Player* myPlayer;
	myPlayer = dynamic_cast<Player*>(m_player.get());
	myPlayer->setScore(m_lastScore);

}
bool Board::playerDidwin() 
//==================playerDidwin=============
{


	for (int i = 0; i < m_staticObject.size(); i++)
		if (m_staticObject[i]->isDead() && typeid(*m_staticObject[i]) == typeid(Door))
			return true;

	return false;
}
void Board::deleteDeadObjects()
//===============deleteDeadObjects===========================
{

	for (size_t i = 0; i < m_staticObject.size(); i++)
		if (m_staticObject[i]->isDead())
			m_staticObject.erase(m_staticObject.begin() + i);
	
	for (size_t i = 0; i < m_movingObject.size(); i++)
		if (m_movingObject[i]->isDead())
			m_movingObject.erase(m_movingObject.begin() + i);
}
bool Board::isHappenedCollision(const GameObject& ob1, const GameObject& ob2) 
//==========isHappenedCollision=============
{
	return ob1.getSprite().getGlobalBounds().intersects(ob2.getSprite().getGlobalBounds());
}

void Board::move(const sf::Vector2i& dir,const float timeThatWasPassed)
//=============move=============
//The function moves the player 
{

	auto stand = sf::Vector2i(0, 0);

	if (dir == stand)
		return;
	
	m_player->setPrevDirection(sf::Vector2f(dir.x,dir.y));
	m_player->move(timeThatWasPassed);

}
void Board::setSettingTexture(sf::Text& text) 
//============setSettingTexture=============
{

	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Black);
	text.setFont(*SingeltonFont::instance().getFontGame(INFORMATION_FONT));
}
void Board::drawBoard(sf::RenderWindow& window) 
//=============drawBoard=============
// The function darws The board(background + objects)
{

	window.draw(m_background);
	for (int i = 0; i < m_staticObject.size();i++)
		m_staticObject[i]->draw(window);
	
	for (int i = 0; i < m_movingObject.size(); i++)
		m_movingObject[i]->draw(window);

	drawInformaionGame(window);
	m_player->draw(window);
}
void Board::drawInformaionGame(sf::RenderWindow& window)
//=============drawInformaionGame===========
{
	Player* myPlayer;

	myPlayer = dynamic_cast<Player*>(m_player.get());

	window.draw(m_bullet);
	window.draw(m_coins);
	m_coinsText.setString("X" + std::to_string(myPlayer->getCoin()));
	m_bulletText.setString("X" + std::to_string(myPlayer->getBullet()));
	m_scoreText.setString("Score:" + std::to_string(myPlayer->getScore()));
	window.draw(m_coinsText);
	window.draw(m_bulletText);
	window.draw(m_scoreText);
}
void Board::openFile()
//=========openFile==========
//The function opens the file and throws an exception when it cannot be opened
{

	m_file.open("Board.txt");
	if (!m_file.is_open())
		throw std::exception("Sory,Can not open The file");
}

Board::Board()
//=======constructor=============
{
	openFile();
	m_bullet.setTexture(*SingeltonTexture::instance().getTexture(CHARACTER, BULLET_TEXTURE));

	m_coins.setTexture(*SingeltonTexture::instance().getTexture(CHARACTER, COIN_TEXTURE));
	m_coins.setPosition(80, 85);

	m_coinsText.setPosition(130, 85);
	setSettingTexture(m_coinsText);

	m_bulletText.setPosition(280, 85);
	m_bullet.setPosition(230, 85);
	setSettingTexture(m_bulletText);

	setSettingTexture(m_scoreText);
	m_scoreText.setPosition(1250, 85);
	

	
	m_bullet.scale(1.6, 1.6);
	m_background.setTexture(*SingeltonTexture::instance().getTexture(BACKGROUND, MAP_BACKGROUND));

}

const sf::Vector2f* Board::getLocationOfPlayer() const {

	return &m_player->getSprite().getPosition();
}
void Board::createObject(char charachter, sf::Vector2f location)
//==========createObject==========
//The function creates objects via factory
{
	if (isupper(charachter)) {
		m_player = MyFactory<MovingObject>::createObject(charachter);
		m_player->setSpriteLocation(location);
		setScoreToPlayer();
		return;
	}
	else if (islower(charachter)) {
		m_staticObject.emplace_back(MyFactory<StaticObject>::createObject(charachter));
		m_staticObject[m_staticObject.size() - 1]->setSpriteLocation(location);
		return;
	}
	else {
		m_movingObject.emplace_back(MyFactory<MovingObject>::createObject(charachter));
		m_movingObject[m_movingObject.size() - 1]->setSpriteLocation(location);
	}	
}
void Board::moveAutoObjects(const float& timeThatWasPassed)
//=============moveAutoObjects===========
{

	for (int i = 0; i < m_movingObject.size(); i++)
	{
		if (Ghost* ghost = dynamic_cast<Ghost*>(m_movingObject[i].get())) 
			ghost->setPrevDirection(m_player->getSprite().getPosition());
			
		m_movingObject[i]->move(timeThatWasPassed);
	}
}
void Board::setBoardPostion(const float x) 
//=============setBoardPostion===========
{
	
	int temp = x - (float)1550 / 2;
	
	m_background.setPosition(temp, 0);
	m_bullet.setPosition(230 + temp, m_bullet.getPosition().y);
	m_bulletText.setPosition(280 + temp, m_bulletText.getPosition().y);
	m_coins.setPosition(80+ temp, m_coins.getPosition().y);
	m_coinsText.setPosition(130 + temp, m_coins.getPosition().y);
	m_scoreText.setPosition(1250 + temp, 85);
}
int Board::getScore() const {
	return m_lastScore;
}