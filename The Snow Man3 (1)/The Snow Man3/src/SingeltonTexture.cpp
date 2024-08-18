#include "SingeltonTexture.h"

//===============SingeltonTexture========================
//The constructor initializes the photos
SingeltonTexture::SingeltonTexture() {

	m_playersTexture[BRICK_TEXTURE].loadFromFile("brick.png");
	m_playersTexture[PLAYER_TEXTURE].loadFromFile("player.png");
	m_playersTexture[START_FALG_TEXTURE].loadFromFile("start_flag.png");
	m_playersTexture[TREE_ONE_TEXTURE].loadFromFile("tree_one.png");
	m_playersTexture[TREE_TWO_TEXTURE].loadFromFile("tree_two.png");
	m_playersTexture[BULLET_TEXTURE].loadFromFile("snow_bullet.png");
	m_playersTexture[COIN_TEXTURE].loadFromFile("coin.png");
	m_playersTexture[COIN_ANIMATION_TEXTURE].loadFromFile("coin_animation.png");
	m_playersTexture[HOLE_ANIMATION_TEXTURE].loadFromFile("hole_animation.png");
	m_playersTexture[ENEMY_TEXTURE].loadFromFile("enemy.png");
	m_playersTexture[SNOW_MAN_ONE_TEXTURE].loadFromFile("snowman_one.png");
	m_playersTexture[SNOW_MAN_TWO_TEXTURE].loadFromFile("snowman_two.png");
	m_playersTexture[LOADING_ANIMATION_TEXTURE].loadFromFile("loading_animation.png");
	m_playersTexture[ROCKET_ANIMATION_TEXTURE].loadFromFile("rocket.png");
	m_playersTexture[GHOST_TEXTURE].loadFromFile("ghost.png");
	m_playersTexture[WATER_TEXTURE].loadFromFile("water.png");
	m_playersTexture[MONEY_BAG_TEXTURE].loadFromFile("money-bag.png");
	
	m_backgrondsTexture[INFO_BACKGROUND].loadFromFile("infogame.png");
	m_backgrondsTexture[MAP_BACKGROUND].loadFromFile("map_background.jpeg");
	m_backgrondsTexture[MENU_BACKGROUND].loadFromFile("menu_background.png");
	m_backgrondsTexture[GAME_OVER_BACKGROUND].loadFromFile("gameover_background.png");
	m_backgrondsTexture[QUIT_BACKGROUND].loadFromFile("quit_background.png");
	m_backgrondsTexture[START_BACKGROUND].loadFromFile("start_background.png");
	
	m_playersTexture[LIGHTNING_TEXTURE].loadFromFile("lightning.png");
	m_playersTexture[DOOR_TEXTURE].loadFromFile("door.png");
	m_playersTexture[GIFT_TEXTURE].loadFromFile("gift.png");
	
}

SingeltonTexture& SingeltonTexture::instance() {
//==================Singelton========================

	static SingeltonTexture instance;
	return instance;

}

const sf::Texture* SingeltonTexture::getTexture(const char & type, const int& num) const 
//=================getTexture=========================
//The function returns the texture according the type and number
{
	if (type == BACKGROUND && num < BACKGROUNDS) 
		return &m_backgrondsTexture[num];
	
	else if (type == CHARACTER && num < CHARACTERS_TEXTURE) 
		return &m_playersTexture[num];
	
	return nullptr;
}