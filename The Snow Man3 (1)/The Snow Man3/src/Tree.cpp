#include "Tree.h"
Tree::Tree()
{

	int texture = rand() % 2;
	if (texture == 0)//creates two different trees
	{
		m_sprite.setTexture(*SingeltonTexture::instance().
			getTexture(CHARACTER, TREE_ONE_TEXTURE));
	}
	else 
	{
		m_sprite.setTexture(*SingeltonTexture::instance().
			getTexture(CHARACTER, TREE_TWO_TEXTURE));
	}

}
