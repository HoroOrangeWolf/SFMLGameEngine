#pragma once
#include <SFML/Graphics.hpp>
#include "PrimitiveRender.h"

class PrimitiveRectangle: public DrawableObject
{
private:
	sf::Vector2f point0, point1, point2, point3;
public:
	PrimitiveRectangle(sf::Vector2f position, sf::Vector2f widthHeight);
	void getToDraw(sf::RenderWindow* window);
	void translate(sf::Vector2f moveBy);
	void scale(float k);
	void rotate(float rotation);
};

