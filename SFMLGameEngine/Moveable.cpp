#include "Moveable.h"

void Moveable::addKeyAndVector(KeyAndVector vecKey)
{
	this->vectors.push_back(vecKey);
}

void Moveable::moveByStoredVector()
{
	sf::Vector2f buff(0.f, 0.f);
	for (int i = 0; i < vectors.size(); ++i)
	{
		KeyAndVector keyandvector = vectors[i];
		if (sf::Keyboard::isKeyPressed(keyandvector.key))
		{
			float x = buff.x;
			float y = buff.y;

			sf::Vector2f toAdd = keyandvector.vector;

			if (toAdd.x > x)
				x = toAdd.x;
			if (toAdd.y > y)
				y = toAdd.y;

			buff = sf::Vector2f(x, y);
		}
	}

	this->move(buff);
}
