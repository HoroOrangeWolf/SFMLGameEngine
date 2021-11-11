#include "PrimitiveRectangle.h"
#include <iostream>

PrimitiveRectangle::PrimitiveRectangle(sf::Vector2f position, sf::Vector2f widthHeight)
{
	this->position = position;
	this->point0 = sf::Vector2f(0.f, 0.f);
	this->point1 = sf::Vector2f(widthHeight.x, 0.f);
	this->point2 = sf::Vector2f(widthHeight.x, widthHeight.y);
	this->point3 = sf::Vector2f(0.f, widthHeight.y);
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

	drawLine(sf::Vector2f(point0.x + position.x, point0.y + position.y), sf::Vector2f(point1.x + position.x, point1.y + position.y), ims);
	drawLine(sf::Vector2f(point1.x + position.x, point1.y + position.y), sf::Vector2f(point2.x + position.x, point2.y + position.y), ims);
	drawLine(sf::Vector2f(point2.x + position.x, point2.y + position.y), sf::Vector2f(point3.x + position.x, point3.y + position.y), ims);
	drawLine(sf::Vector2f(point3.x + position.x, point3.y + position.y), sf::Vector2f(point0.x + position.x, point0.y + position.y), ims);

	

	text = sf::Texture();

	text.loadFromImage(ims);

	arr.setTexture(text);

	arr.setPosition(sf::Vector2f(0.f, 0.f));


	window->draw(arr);
}
