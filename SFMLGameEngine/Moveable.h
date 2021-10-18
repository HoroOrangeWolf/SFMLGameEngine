#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "KeyAndVector.h"

class Moveable: public sf::Shape
{
private:
	std::list<KeyAndVector> vectors;
public:
	void addKeyAndVector(KeyAndVector vecKey);
	void moveByStoredVector();

};

