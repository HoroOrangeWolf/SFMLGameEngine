#include "LineSegment.h"

LineSegment::LineSegment(sf::Vector2f point1, sf::Vector2f point2)
{
	this->point1 = point1;
	this->point2 = point2;
}

sf::Sprite& LineSegment::getToDraw()
{
	sf::VertexArray buff;

	this->drawLine(point1, point2, ims);

	sf::Sprite sp;

	return sp;
}
