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

void PrimitiveRectangle::getToDraw(sf::RenderWindow* window)
{
	if (!isChanged)
	{
		window->draw(arr);
		return;
	}

	isChanged = false;

	ims = sf::Image();

	ims.create(window->getSize().x, window->getSize().y, sf::Color::Transparent);

	drawLine(point0, point1, ims);
	drawLine(point1, point2, ims);
	drawLine(point2, point3, ims);
	drawLine(point3, point0, ims);

	recuFiller(ims, color, point2.x / 2, point2.y / 2);

	text = sf::Texture();

	text.loadFromImage(ims);

	arr.setTexture(text);

	arr.setPosition(position);


	window->draw(arr);
}
