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

	recuFiller(ims, color, (point0.x + point2.x)/2 + position.x, (point0.y + point2.y)/2 + position.y);

	text = sf::Texture();

	text.loadFromImage(ims);

	arr.setTexture(text);

	arr.setPosition(sf::Vector2f(0.f, 0.f));


	window->draw(arr);
}

void PrimitiveRectangle::translate(sf::Vector2f moveBy)
{
	isChanged = true;
	position = sf::Vector2f(position.x + moveBy.x, position.y + moveBy.y);
}

void PrimitiveRectangle::scale(float k)
{
	isChanged = true;
	point1 = sf::Vector2f(point1.x * k, point1.y * k);
	point2 = sf::Vector2f(point2.x * k, point2.y * k);
	point3 = sf::Vector2f(point3.x * k, point3.y * k);
}

void PrimitiveRectangle::rotate(float rotation)
{
	isChanged = true;
	rotation = rotation * (M_PI / 180);
	point0 = sf::Vector2f(point0.x * std::cos(rotation) - point0.y * std::sin(rotation), point0.x * std::sin(rotation) + point0.y * std::cos(rotation));
	point1 = sf::Vector2f(point1.x * std::cos(rotation) - point1.y * std::sin(rotation), point1.x * std::sin(rotation) + point1.y * std::cos(rotation));
	point2 = sf::Vector2f(point2.x * std::cos(rotation) - point2.y * std::sin(rotation), point2.x * std::sin(rotation) + point2.y * std::cos(rotation));
	point3 = sf::Vector2f(point3.x * std::cos(rotation) - point3.y * std::sin(rotation), point3.x * std::sin(rotation) + point3.y * std::cos(rotation));
}
