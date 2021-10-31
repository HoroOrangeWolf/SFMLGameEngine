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

	ims.create(point1.x + 1, point1.y + 1, sf::Color::Transparent);

	this->drawLine(point0, point2, ims);
	this->drawLine(point2, point1, ims);
	this->drawLine(point0, point1, ims);

	for (int i = 0; i < point1.x; ++i) 
		if (ims.getPixel(i, (point1.y + 1) / 2) == color && ims.getPixel(i + 1, (point1.y + 1) / 2) == sf::Color::Transparent) {
			recuFiller(ims, color, i + 1, (point1.y + 1) / 2);
			break;
		}
	

	text = sf::Texture();

	text.loadFromImage(ims);

	arr.setTexture(text);

	arr.setPosition(position);


	return arr;
}
