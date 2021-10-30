#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
class PrimitiveRender
{

protected:
	bool isChanged = true;
	void drawLine(sf::Vector2f points0, sf::Vector2f points1, bool **tab);
	void recuFiller(bool** elements, int x, int y);
public:
	sf::VertexArray arr = sf::VertexArray();
	void drawLine(sf::Vector2f points0, sf::Vector2f points1, sf::VertexArray& ar);
	virtual sf::VertexArray& getToDraw() = 0;
};

