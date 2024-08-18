#include "CollisionHandling.h"
#include "SingeltonSound.h"
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include <Player.h>
#include <Brick.h>
#include "hole.h"
#include "Coin.h"
#include "Lightning.h"
#include "Bullet.h"
#include "Door.h"
#include "Ghost.h"
#include "Gift.h"
#include "Shot.h"
#include "Water.h"
#include "Enemy.h"
#include "Rocket.h"
#include "MoneyBag.h"
namespace // anonymous namespace — the standard way to make function "static"
{

    void enemyAndBrick(GameObject& enemyObg, GameObject& bricktObj) 
        // collision between enemy to brick
    {

        Enemy& enemy = dynamic_cast<Enemy&>(enemyObg);
        enemy.moveBack();
        enemy.changeDirection();
    }
    void playerAndGift(GameObject& playerObg, GameObject& giftObj) 
        // collision between player to gift
    {

        Player& player = dynamic_cast<Player&>(playerObg);
        Gift& gift = dynamic_cast<Gift&>(giftObj);

        if(gift.getNumber() > -1)
            SingeltonSound::instance().doSoundEft(GIFT_EFT);
        else SingeltonSound::instance().doSoundEft(BAD_GIFT_COLLECTED_EFT);
        player.setScore(player.getScore() + gift.getNumber());
        gift.setDead();
    }
    void playerAndDoor(GameObject& playerObg, GameObject& doortObj) 
        // collision between player to door
    {

        SingeltonSound::instance().doSoundEft(WIN_EFT);
        Door& door = dynamic_cast<Door&>(doortObj);

        door.setDead();
    }
    void playerAndBullet(GameObject& playerObg, GameObject& BulletObj) 
        // collision between player to bullet
    {

        SingeltonSound::instance().doSoundEft(COLLECT_AMMO_EFT);
        Player& player = dynamic_cast<Player&>(playerObg);
        Bullet& bullet = dynamic_cast<Bullet&>(BulletObj);

        bullet.setDead();
        player.setBullet(player.getBullet() + 1);
    }

    void playerAndLightning(GameObject& playerObg, GameObject& lightningObj) 
        // collision between player to lithning
    {

        Player& player = dynamic_cast<Player&>(playerObg);
        Lightning& lightning = dynamic_cast<Lightning&>(lightningObj);
        SingeltonSound::instance().doSoundEft(SUPER_POWER_EFT);
        lightning.setDead();
        player.extraSpeed();
    }
    void enemyAndShot(GameObject& enemyObg, GameObject& shotObj)
        // collision between enemy to shot
    {
     
        Enemy& enemy = dynamic_cast<Enemy&>(enemyObg);
        Shot& shot = dynamic_cast<Shot&>(shotObj);

        enemy.setDead();
        shot.setDead();
    }
    void wallAndShot(GameObject& shotObj , GameObject& brickObg)
        // collision between enemy to shot
    {
        Shot& shot = dynamic_cast<Shot&>(shotObj);
        shot.setDead();
    }
    void rocketAndWall(GameObject& rocketObj, GameObject& brickObg)
        // collision between rocket to shot
    {
        Rocket& rocket = dynamic_cast<Rocket&>(rocketObj);
        rocket.setDead();
    }

    void rocketAndEnemy(GameObject& rocketObj, GameObject& enemyObg) {

        Enemy& enemy = dynamic_cast<Enemy&>(enemyObg);
 
        enemy.setDead();
   
    }
    void playerAndHole(GameObject& playerObg, GameObject& holeObg) 
        // collision between player to hole
    {

        Player& player = dynamic_cast<Player&>(playerObg);
    
        SingeltonSound::instance().doSoundEft(DEAD_EFT);
        player.setScore(int(player.getScore()/2));
        player.setDead();

    }
    void playerAndCoin(GameObject& playerObg, GameObject& coinObg) 
        // collision between player to coin
    {

        Player& player = dynamic_cast<Player&>(playerObg);
        Coin& coin = dynamic_cast<Coin&>(coinObg);
        SingeltonSound::instance().doSoundEft(COLLECTED_EFT);
        player.setCoin(player.getCoin() + 1);
        player.setScore(player.getScore() + 7);
        coin.setDead();
    }

    void playerAndBrick(GameObject& playerObg,
                      GameObject& brickObg)
    {
        Player& player = dynamic_cast<Player&>(playerObg);
        Brick& brick = dynamic_cast<Brick&>(brickObg);

        player.moveBack();

    }
    void ghostAndShot(GameObject& ghostObg, GameObject& shotObg)
    {
        Ghost& ghost = dynamic_cast<Ghost&>(ghostObg);
        Shot& shot = dynamic_cast<Shot&>(shotObg);

        shot.setDead();
        ghost.setDead();
  
    }
    void ghostAndRocket(GameObject& ghostObg, GameObject& rocketObg)
    {
        Ghost& ghost = dynamic_cast<Ghost&>(ghostObg);
        ghost.setDead();

    }
    void playerAndMoneyBag(GameObject& playerObg, GameObject& moneyBagObg)
    {
        MoneyBag& moneyBag = dynamic_cast<MoneyBag&>(moneyBagObg);
        Player& player = dynamic_cast<Player&>(playerObg);
        SingeltonSound::instance().doSoundEft(MONEY_BAG_EFT);

        moneyBag.setDead();
        player.setScore(player.getScore() + 25);
    }

  
    using HitFunctionPtr = void (*)(GameObject&, GameObject&);
    // typedef void (*HitFunctionPtr)(GameObject&, GameObject&);
    using Key = std::pair<std::type_index, std::type_index>;
    // std::unordered_map is better, but it requires defining good hash function for pair
    using HitMap = std::map<Key, HitFunctionPtr>;

    HitMap initializeCollisionMap()
    {
        HitMap phm;
        phm[Key(typeid(Player), typeid(Brick))] = &playerAndBrick;
        phm[Key(typeid(Player), typeid(Coin))] = &playerAndCoin;
        phm[Key(typeid(Player), typeid(Hole))] = &playerAndHole;
        phm[Key(typeid(Player), typeid(Lightning))] = &playerAndLightning;
        phm[Key(typeid(Player), typeid(Bullet))] = &playerAndBullet;
        phm[Key(typeid(Player), typeid(Gift))] = &playerAndGift;
        phm[Key(typeid(Player), typeid(Door))] = &playerAndDoor;
        phm[Key(typeid(Enemy), typeid(Brick))] = &enemyAndBrick;
        phm[Key(typeid(Enemy), typeid(Hole))] = &enemyAndBrick;
        phm[Key(typeid(Enemy), typeid(Door))] = &enemyAndBrick;
        phm[Key(typeid(Player),typeid(Enemy))] = &playerAndHole;
        phm[Key(typeid(Enemy), typeid(Shot))] = &enemyAndShot;
        phm[Key(typeid(Enemy), typeid(Water))] = &enemyAndBrick;
        phm[Key(typeid(Ghost), typeid(Shot))] = &ghostAndShot;
        phm[Key(typeid(Ghost), typeid(Rocket))] = &ghostAndRocket;
        phm[Key(typeid(Shot), typeid(Brick))] = &wallAndShot;
        phm[Key(typeid(Rocket), typeid(Brick))] = &rocketAndWall;
        phm[Key(typeid(Rocket), typeid(Enemy))] = &rocketAndEnemy;
        phm[Key(typeid(Player), typeid(Ghost))] = &playerAndHole;
        phm[Key(typeid(Player), typeid(Water))] = &playerAndHole;
        phm[Key(typeid(Player), typeid(MoneyBag))] = &playerAndMoneyBag;
        return phm;
    }

    HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
    {
        static HitMap collisionMap = initializeCollisionMap();
        auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        return mapEntry->second;
    }

} // end namespace

void processCollision(GameObject& object1, GameObject& object2)
{
    auto phf = lookup(typeid(object1), typeid(object2));
    if (phf)
        phf(object1, object2);
}
