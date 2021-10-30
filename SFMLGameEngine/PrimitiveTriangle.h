#pragma once
#include <SFML/Graphics.hpp>
#include "PrimitiveRender.h"

class PrimitiveTriangle: public PrimitiveRender
{
private:
	sf::Vector2f position, point0, point1, point2;
public:
	PrimitiveTriangle(sf::Vector2f position, sf::Vector2f widthHeight);
	sf::VertexArray& getToDraw();
};

