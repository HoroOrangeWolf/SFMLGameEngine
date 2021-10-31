#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

#define M_PI 3.14159265358979323846

class PrimitiveRender
{

protected:
	bool isChanged = true;
	sf::Vector2f position;
	void drawLine(sf::Vector2f points0, sf::Vector2f points1, bool **tab);
	void recuFiller(bool** elements, int x, int y);
public:
	PrimitiveRender();
	void setPosition(sf::Vector2f position);
	sf::VertexArray arr = sf::VertexArray();
	void drawLine(sf::Vector2f points0, sf::Vector2f points1, sf::VertexArray& ar);
	virtual sf::VertexArray& getToDraw() = 0;
};

