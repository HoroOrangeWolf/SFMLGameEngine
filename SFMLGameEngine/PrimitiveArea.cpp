#include "PrimitiveArea.h"
#include <cmath>


PrimitiveArea::PrimitiveArea(sf::Vector2f position, float r)
{
	this->position = position;
	this->r = r;
}

sf::VertexArray& PrimitiveArea::getToDraw()
{
	if (!isChanged)
		return arr;

	isChanged = false;

	arr = sf::VertexArray();

	float step = 1.f / this->r;

	float xc = position.x + r;
	float yc = position.y + r;


	float value = 0;

	for (value; value < 2 * M_PI; value += step)
	{
		sf::Vertex vertex;

		vertex.color = sf::Color::Red;
		vertex.position = sf::Vector2f(round(xc + (double)r * cos(value) + 0.5), round(yc + (double)r * sin(value) + 0.5));

		arr.append(vertex);
	}


	return arr;
}
