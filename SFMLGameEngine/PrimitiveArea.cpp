#include "PrimitiveArea.h"
#include <cmath>


PrimitiveArea::PrimitiveArea(sf::Vector2f position, float r)
{
	this->position = position;
	this->r = r;
}

sf::Sprite& PrimitiveArea::getToDraw()
{
	if (!isChanged)
		return arr;

	isChanged = false;

	ims= sf::Image();

	ims.create(r * 2 + 1, r * 2 + 1, sf::Color::Transparent);

	float step = 1.f / this->r;

	float xc = r;
	float yc = r;

	float value = 0;

	for (value; value < 2 * M_PI; value += step)
	{
		sf::Vertex vertex;

		vertex.color = sf::Color::Red;
		vertex.position = sf::Vector2f(round(xc + (double)r * cos(value) + 0.5), round(yc + (double)r * sin(value) + 0.5));

		ims.setPixel(vertex.position.x, vertex.position.y, sf::Color::Red);
	}

	text = sf::Texture();

	text.loadFromImage(ims);

	arr.setTexture(text);

	arr.setPosition(position);

	return arr;
}
