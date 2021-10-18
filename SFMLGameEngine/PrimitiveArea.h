#pragma once
#include <SFML/Graphics.hpp>


class PrimitiveArea
{
private:
	sf::Vector2f position;
	float r = 0.f;

public:
	PrimitiveArea(sf::Vector2f position, float r);
	sf::VertexArray getToDraw();
};

