#pragma once
#include <SFML/Graphics.hpp>
#include "KeyAndVector.h"
#include <list>

class MoveableBlock: public sf::RectangleShape
{
private:
	std::list<KeyAndVector> vectors;
	sf::Vector2f constantMovement;
	int level=0;
public:
	MoveableBlock(sf::Vector2f vec) :RectangleShape(vec) {
		this->constantMovement = sf::Vector2f(0.f, 0.f);
	}
	void addKeyAndVector(KeyAndVector vecKey);
	void moveByStoredVector();
	void clearMovement();
	int getLevel();
	void setLevel(int level);
};

