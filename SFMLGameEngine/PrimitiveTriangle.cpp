#include "PrimitiveTriangle.h"

void PrimitiveTriangle::drawLine(sf::Vector2f points0, sf::Vector2f points1, sf::VertexArray& ar)
{
	float xStart = points0.x;
	float yStart = points0.y;

	float xEnd = points1.x;
	float yEnd = points1.y;

	if (abs(xStart - xEnd) > abs(yStart - yEnd)) {
		float m = (yEnd - yStart) / (xEnd - xStart);

		float y = yStart;
		for (float i = xStart; i <= xEnd; i += 1.f) {
			sf::Vertex vertex1;
			vertex1.position = sf::Vector2f(i, (int)y + 0.5);
			vertex1.color = sf::Color::Red;
			ar.append(vertex1);
			y += m;
		}
	}
	else {
		float m = abs(xEnd - xStart) / abs(yEnd - yStart);

		float y = xStart;
		for (float i = yStart; i <= yEnd; i += 1.f) {
			sf::Vertex vertex1;
			vertex1.position = sf::Vector2f((int)y + 0.5, i);
			vertex1.color = sf::Color::Red;
			ar.append(vertex1);
			y += m;
		}
	}
}

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
