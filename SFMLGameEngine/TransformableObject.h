#pragma once

#include <SFML/Window.hpp>

class TransformableObject
{
public:
	virtual void translate(sf::Vector2f moveBy) = 0;
	virtual void rotate(float rotation) = 0;
	virtual void scale(float k) = 0;
};

