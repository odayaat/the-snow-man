#pragma once
#include <SFML/Graphics.hpp>
class GameObject
{
public:

	//=============virtual functions========
	virtual void draw(sf::RenderWindow&);

	//===========Constructor=============
	GameObject() = default;

	//=========Destractor================
	virtual ~GameObject() = default;
	bool isDead() const;

	void moveSprite(const sf::Vector2f& );

	//===========getter method=============
	const sf::Sprite& getSprite() const;

	//===========setter method=============
	void setDead();
	void setSpriteLocation(const sf::Vector2f & location);

protected:
	bool m_isDead = false;
	sf::Sprite m_sprite;

private:



};
