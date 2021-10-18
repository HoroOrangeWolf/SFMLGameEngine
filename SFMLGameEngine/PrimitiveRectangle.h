#pragma once
#include <SFML/Graphics.hpp>

class PrimitiveRectangle
{
private:
	sf::Vector2f position, point0, point1, point2, point3;
	void drawLine(sf::Vector2f point0, sf::Vector2f point1, sf::VertexArray &ar);


public:
	PrimitiveRectangle(sf::Vector2f position, sf::Vector2f widthHeight);
	sf::VertexArray getToDraw();
};

