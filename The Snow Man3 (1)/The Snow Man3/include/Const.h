#pragma once
#include <SFML/Graphics.hpp>

//===============Consts=====================
const char BACKGROUND = 'b';
const char CHARACTER = 'c';

const int THE_LENGTH_OF_SCREEN = 4450;
const int FOR_SECONDS = 4000;
const int SIZE_OF_BRICK = 50;
const int ROW_MAP = 17;
const int COL_MAP = 89;
const int WIDTH = 1550;
const int HEIGHT = 800;
const float SPEED_ENEMY = 90;
const int THREE_SECONDS = 3000;
const char GAME_OVER = '!';
const char BRICK = 'b';
const char MONEY_BAG = 'm';
const char MY_PLAYER = 'P';
const char TREE = 't';
const char SNOW_MAN = 's';
const char START_FLAG = 'f';
const char BULLET = 'x';
const char COIN = 'c';
const char HOLE = 'h';
const char WATER = 'w';
const char LIGHTNING = 'l';
const char GIFT = 'g';
const char DOOR = 'd';
const char ENEMY = '1';
const char SHOT = '2';
const char ROCKET = '3';
const char GHOST = '4';
const float MAXIMUM_SPEED = 0.35;
const float GHOST_SPEED = 0.18;
const float PLAYER_SPEED = 250;
const float SHOT_SPEED = 250;

const sf::Vector2i START_BUTTON_LOCATION = sf::Vector2i(668, 305),
					INFO_BUTTON_LOCATION = sf::Vector2i(692, 405),
					PREV_BUTTON_LOCATION = sf::Vector2i(692, 660),
					QUIT_BUTTON_LOCATION = sf::Vector2i(692, 505);

enum characterTextur_t {MONEY_BAG_TEXTURE,WATER_TEXTURE,LIGHTNING_TEXTURE, GHOST_TEXTURE,ROCKET_ANIMATION_TEXTURE,GIFT_TEXTURE,DOOR_TEXTURE, LOADING_ANIMATION_TEXTURE,
	HOLE_ANIMATION_TEXTURE,PLAYER_TEXTURE, BRICK_TEXTURE, TREE_TWO_TEXTURE, COIN_TEXTURE,ENEMY_TEXTURE,
					TREE_ONE_TEXTURE,COIN_ANIMATION_TEXTURE,SNOW_MAN_ONE_TEXTURE, SNOW_MAN_TWO_TEXTURE, START_FALG_TEXTURE, BULLET_TEXTURE, CHARACTERS_TEXTURE};

enum backgrounds_t {
	START_BACKGROUND, INFO_BACKGROUND,MAP_BACKGROUND, GAME_OVER_BACKGROUND,MENU_BACKGROUND, QUIT_BACKGROUND,BACKGROUNDS
};

enum sounds_t{ MONEY_BAG_EFT,SELECT_EFT,COLLECT_AMMO_EFT,SUPER_POWER_EFT, SHOT_EFT,COLLECTED_EFT, WIN_EFT, DEAD_EFT,BAD_GIFT_COLLECTED_EFT, GIFT_EFT,SOUNDS_EFT};

enum fonts_t{SUPER_MARIO_FONT,INFORMATION_FONT,FONTS};
enum music_t { MENU_MUSIC,GAME_MUSIC, MUSIC };

