#pragma once
#include <SFML/Graphics.hpp>
#include "PrimitiveRender.h"

class PrimitiveTriangle: public DrawableObject
{
private:
	sf::Vector2f position, point0, point1, point2;
public:
	PrimitiveTriangle(sf::Vector2f position, sf::Vector2f widthHeight);
	void getToDraw(sf::RenderWindow* window);
};

