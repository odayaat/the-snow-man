#include "Ghost.h"
#include <iostream>


Ghost::Ghost()
//============Constructor=============
{

    m_ghostAnim = Animation(sf::Vector2i(3, 1), 0.36, *SingeltonTexture::instance().getTexture(CHARACTER, GHOST_TEXTURE));//initialize the animation
    m_sprite.setTexture(*SingeltonTexture::instance().getTexture(CHARACTER, GHOST_TEXTURE));
    m_sprite.setTextureRect(*m_ghostAnim.get_uvRect());
    m_sprite.scale(0.35, 0.35);
    m_moveBehavior = std::make_unique<SmartMove>();

}

void Ghost::move(const float& timepassed)
//===========move==============
{

    m_ghostAnim.updateAnimation(0, timepassed);//calculates the right animation
    m_sprite.setTextureRect(*m_ghostAnim.get_uvRect());//sets the correct texture
    m_speed = GHOST_SPEED * timepassed;
    m_moveBehavior->moveObject(*this);
    
}
