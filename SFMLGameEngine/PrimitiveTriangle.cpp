#include "PrimitiveTriangle.h"

PrimitiveTriangle::PrimitiveTriangle(sf::Vector2f position, sf::Vector2f widthHeight)
{
	this->position = position;

	this->point0 = sf::Vector2f(position.x, position.y);
	this->point1 = sf::Vector2f(position.x + widthHeight.x, position.y + widthHeight.y);
	this->point2 = sf::Vector2f(position.x, position.y + widthHeight.y);
}

sf::VertexArray PrimitiveTriangle::getToDraw()
{
	sf::VertexArray ver;
	this->drawLine(point0, point2, ver);
	this->drawLine(point2, point1, ver);
	this->drawLine(point0, point1, ver);

	return ver;
}
