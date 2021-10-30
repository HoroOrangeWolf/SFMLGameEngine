#include "PrimitiveRectangle.h"
#include <iostream>

PrimitiveRectangle::PrimitiveRectangle(sf::Vector2f position, sf::Vector2f widthHeight)
{
	this->position = position;
	this->point0 = sf::Vector2f(position.x, position.y);
	this->point1 = sf::Vector2f(position.x + widthHeight.x, position.y);
	this->point2 = sf::Vector2f(position.x + widthHeight.x, position.y + widthHeight.y);
	this->point3 = sf::Vector2f(position.x, position.y + widthHeight.y);

	
}

sf::VertexArray PrimitiveRectangle::getToDraw()
{
	sf::VertexArray ver;

	this->drawLine(point0, point1, ver);
	this->drawLine(point1, point2, ver);
	this->drawLine(point3, point2, ver);
	this->drawLine(point0, point3, ver);

	return ver;
}
