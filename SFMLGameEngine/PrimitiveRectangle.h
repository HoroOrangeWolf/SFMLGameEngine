#pragma once
#include <SFML/Graphics.hpp>
#include "PrimitiveRender.h"

class PrimitiveRectangle: public PrimitiveRender
{
private:
	sf::Vector2f point0, point1, point2, point3;
public:
	PrimitiveRectangle(sf::Vector2f position, sf::Vector2f widthHeight);
	sf::Sprite& getToDraw();
};

