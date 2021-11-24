#include "LineSegment.h"

LineSegment::LineSegment(sf::Vector2f point1, sf::Vector2f point2)
{
	this->point1 = point1;
	this->point2 = point2;
}

void LineSegment::getToDraw(sf::RenderWindow* window)
{
	if (!isChanged)
	{
		window->draw(arr);
		return;
	}

	isChanged = false;

	ims = sf::Image();

	ims.create(window->getSize().x, window->getSize().y, sf::Color::Transparent);

	drawLine(sf::Vector2f(point1.x + position.x, point1.y + position.y), sf::Vector2f(point2.x + position.x, point2.y + position.y), ims);

	text = sf::Texture();

	text.loadFromImage(ims);

	arr.setTexture(text);

	arr.setPosition(sf::Vector2f(0.f, 0.f));

	window->draw(arr);
}

void LineSegment::translate(sf::Vector2f moveBy)
{

	position = sf::Vector2f(position.x + moveBy.x, position.y + moveBy.y);
}

void LineSegment::scale(float k)
{
	point2 = sf::Vector2f(point2.x * k, point2.y * k);
}

void LineSegment::rotate(float rotation)
{
	point1 = sf::Vector2f(point1.x * std::cos(rotation) - point1.y * std::sin(rotation), point1.x * std::sin(rotation) + point1.y * std::cos(rotation));
	point2 = sf::Vector2f(point2.x * std::cos(rotation) - point2.y * std::sin(rotation), point2.x * std::sin(rotation) + point2.y * std::cos(rotation));
}

