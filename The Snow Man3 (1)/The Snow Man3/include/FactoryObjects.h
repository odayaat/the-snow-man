#pragma once
#include "Brick.h"
#include "Const.h"
#include "MyFactory.h"
#include "Door.h"
#include "Coin.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Tree.h"
#include "SnowMan.h"
#include "StartFlag.h"
#include "Player.h"
#include "Lightning.h"
#include "Hole.h"
#include "Gift.h"
#include "Shot.h"
#include "Rocket.h"
#include "Ghost.h"
#include "Water.h"
#include "MoneyBag.h"

bool MoneyBag::m_registerit = MyFactory<StaticObject>::registerit(MONEY_BAG,
	[]() -> std::unique_ptr<StaticObject> { return std::make_unique<MoneyBag>(); });
bool Lightning::m_registerit = MyFactory<StaticObject>::registerit(LIGHTNING,
	[]() -> std::unique_ptr<StaticObject> { return std::make_unique<Lightning>(); });

bool Brick::m_registerit = MyFactory<StaticObject>::registerit(BRICK,
	[]() -> std::unique_ptr<StaticObject> { return std::make_unique<Brick>(); });

bool Bullet::m_registerit = MyFactory<StaticObject>::registerit(BULLET,
	[]() -> std::unique_ptr<StaticObject> { return std::make_unique<Bullet>(); });

bool Coin::m_registerit = MyFactory<StaticObject>::registerit(COIN,
	[]() -> std::unique_ptr<StaticObject> { return std::make_unique<Coin>(); });

bool Enemy::m_registerit = MyFactory<MovingObject>::registerit(ENEMY,
	[]() -> std::unique_ptr<MovingObject> { return std::make_unique<Enemy>(); });

bool Hole::m_registerit = MyFactory<StaticObject>::registerit(HOLE,
	[]() -> std::unique_ptr<StaticObject> { return std::make_unique<Hole>(); });

bool Door::m_registerit = MyFactory<StaticObject>::registerit(DOOR,
	[]() -> std::unique_ptr<StaticObject> { return std::make_unique<Door>(); });

bool Tree::m_registerit = MyFactory<StaticObject>::registerit(TREE,
	[]() -> std::unique_ptr<StaticObject> { return std::make_unique<Tree>(); });

bool Gift::m_registerit = MyFactory<StaticObject>::registerit(GIFT,
	[]() -> std::unique_ptr<StaticObject> { return std::make_unique<Gift>(); });

bool StartFlag::m_registerit = MyFactory<StaticObject>::registerit(START_FLAG,
	[]() -> std::unique_ptr<StaticObject> { return std::make_unique<StartFlag>(); });

bool SnowMan::m_registerit = MyFactory<StaticObject>::registerit(SNOW_MAN,
	[]() -> std::unique_ptr<StaticObject> { return std::make_unique<SnowMan>(); });

bool Ghost::m_registerit = MyFactory<MovingObject>::registerit(GHOST,
	[]() -> std::unique_ptr<MovingObject> { return std::make_unique<Ghost>(); });

bool Player::m_registerit = MyFactory<MovingObject>::registerit(MY_PLAYER,
	[]() -> std::unique_ptr<MovingObject> { return std::make_unique<Player>(); });

bool Shot::m_registerit = MyFactory<MovingObject>::registerit(SHOT,
	[]() -> std::unique_ptr<MovingObject> { return std::make_unique<Shot>(); });

bool Rocket::m_registerit = MyFactory<MovingObject>::registerit(ROCKET,
	[]() -> std::unique_ptr<MovingObject> { return std::make_unique<Rocket>(); });

bool Water::m_registerit = MyFactory<StaticObject>::registerit(WATER,
	[]() -> std::unique_ptr<StaticObject> { return std::make_unique<Water>(); });