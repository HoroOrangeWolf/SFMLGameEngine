#include "PrimitiveRectangle.h"
#include <iostream>

PrimitiveRectangle::PrimitiveRectangle(sf::Vector2f position, sf::Vector2f widthHeight)
{
	this->position = position;
	this->point0 = sf::Vector2f(0.f, 0.f);
	this->point1 = sf::Vector2f(widthHeight.x, 0.f);
	this->point2 = sf::Vector2f(widthHeight.x, widthHeight.y);
	this->point3 = sf::Vector2f(0, widthHeight.y);
}

sf::Sprite& PrimitiveRectangle::getToDraw()
{
	if (!isChanged)
		return arr;

	isChanged = false;

	ims = sf::Image();

	ims.create(point3.x + 1, point3.y + 1, sf::Color::Transparent);

	drawLine(point0, point1, ims);
	drawLine(point1, point2, ims);
	drawLine(point2, point3, ims);
	drawLine(point3, point0, ims);

	text = sf::Texture();

	text.loadFromImage(ims);

	arr.setTexture(text);

	arr.setPosition(position);


	return arr;
}
