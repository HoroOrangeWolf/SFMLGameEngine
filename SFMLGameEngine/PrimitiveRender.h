#pragma once
#include <SFML/Graphics.hpp>
class PrimitiveRender
{
public:
	void drawLine(sf::Vector2f points0, sf::Vector2f points1, sf::VertexArray& ar);
};

