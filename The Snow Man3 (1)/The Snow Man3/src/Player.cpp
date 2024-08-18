#include "Player.h"
#include <iostream>
Player::Player()
//==============Constructor==================
{
	m_moveBehavior = std::make_unique<StriteMove>();
	m_prevDirection = sf::Vector2f(0, 1);//down // the member saves the last step
	m_playerAnim = Animation( sf::Vector2i(4, 4), 0.26, *SingeltonTexture::instance().getTexture(CHARACTER, PLAYER_TEXTURE));//initialize the animation
	m_sprite.setTexture(*SingeltonTexture::instance().getTexture(CHARACTER, PLAYER_TEXTURE));
	m_sprite.setScale(1.2, 1.2);
	m_sprite.setTextureRect(*m_playerAnim.get_uvRect());
}

void Player::move(const float& timeThatWasPassed)
//============move============
{
	int correctRowForAnimation = m_playerAnim.getRowByDirection(m_prevDirection);
	
	m_playerAnim.updateAnimation(correctRowForAnimation, timeThatWasPassed);//calculates the right animation
	m_sprite.setTextureRect(*m_playerAnim.get_uvRect());//sets the correct texture

	m_speed = PLAYER_SPEED * timeThatWasPassed + m_extraSpeedPlayer;
	m_moveBehavior->moveObject(*this);

}
void Player::setScore(const int& num) 
//=============setScore=============
{

	if (m_score + num < 0)
		m_score = 0;
	else m_score = num;
}
int Player::getScore() const
//=============getScore=============
{
	return m_score;

}

int Player::getCoin() const
//=============getCoin=============
{
	return m_coins;
}
void Player::moveBack() 
//=============moveBack=============
{
	m_sprite.move(-sf::Vector2(m_prevDirection.x * m_speed, m_prevDirection.y * m_speed));
}

void Player::setCoin(const int& num)
//=============setCoin=============
{
	m_coins = num;
}

void Player::extraSpeed()
//=============extraSpeed=============
{

	m_extraSpeedPlayer += 0.2;
}
void Player::setBullet(const int& num) 
//=============setBullet=============
{

	m_bullet = num;
}
int Player::getBullet() const
//=============getBullet=============
{
	return m_bullet;

}

void Player::setRocket(const int & num) {
	m_rocket = num;
}

int Player::getRocket() const{
	return m_rocket;
}
