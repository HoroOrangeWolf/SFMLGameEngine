#include "Moveable.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void MoveableBlock::addKeyAndVector(KeyAndVector vecKey)
{
	this->vectors.push_back(vecKey);
}

void MoveableBlock::moveByStoredVector()
{
	float x = 0.f;
	float y = 0.f;
	sf::Vector2f current = this->getPosition();

	std::list<KeyAndVector>::iterator keystore = vectors.begin();

	while (keystore != vectors.end())
	{
		KeyAndVector keyandvector = *keystore;
		if (sf::Keyboard::isKeyPressed(keyandvector.key))
		{
			sf::Vector2f toAdd = keyandvector.vector;

			x += toAdd.x;

			y += toAdd.y;
		}

		keystore++;
	}

	this->move(sf::Vector2f(x, y));
}

void MoveableBlock::clearMovement()
{
	vectors.clear();
}

int MoveableBlock::getLevel()
{
	return this->level;
}

void MoveableBlock::setLevel(int level) {
	this->level = level;
}