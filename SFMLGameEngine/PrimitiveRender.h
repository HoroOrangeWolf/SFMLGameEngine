#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
class PrimitiveRender
{
private:
	void fillPrimitive(bool** elements, int width,int height);
	void recuFiller(bool** elements,int x,int y,int width, int height);
public:
	void drawLine(sf::Vector2f points0, sf::Vector2f points1, sf::VertexArray& ar);
	virtual sf::VertexArray getToDraw() = 0;
};

