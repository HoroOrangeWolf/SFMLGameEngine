#include "PrimitiveTriangle.h"
#include <iostream>

PrimitiveTriangle::PrimitiveTriangle(sf::Vector2f position, sf::Vector2f widthHeight)
{
	this->position = position;

	this->point0 = sf::Vector2f(0.f, 0.f);
	this->point1 = sf::Vector2f(widthHeight.x, widthHeight.y);
	this->point2 = sf::Vector2f(0.f, widthHeight.y);
}

sf::Sprite& PrimitiveTriangle::getToDraw()
{
	if (!isChanged)
		return arr;

	isChanged = false;

	ims = sf::Image();

	ims.create(point2.x + 1, point2.y + 1, sf::Color::Transparent);

	this->drawLine(point0, point2, ims);
	this->drawLine(point2, point1, ims);
	this->drawLine(point0, point1, ims);

	text = sf::Texture();

	text.loadFromImage(ims);

	arr.setTexture(text);

	arr.setPosition(position);


	return arr;
}
