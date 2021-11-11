#include "PrimitiveTriangle.h"
#include <iostream>

PrimitiveTriangle::PrimitiveTriangle(sf::Vector2f position, sf::Vector2f widthHeight)
{
	this->position = position;

	this->point0 = sf::Vector2f(0.f, 0.f);
	this->point1 = sf::Vector2f(widthHeight.x, widthHeight.y);
	this->point2 = sf::Vector2f(0.f, widthHeight.y);
}

void PrimitiveTriangle::getToDraw(sf::RenderWindow* window)
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
	drawLine(sf::Vector2f(point2.x + position.x, point2.y + position.y), sf::Vector2f(point0.x + position.x, point0.y + position.y), ims);

	double Ax = point0.x,
		Ay = point0.y,
		Bx = (point1.x + point2.x) / 2,
		By = (point1.y + point2.y) / 2,
		Cx = point2.x,
		Cy = point2.y,
		Dx = (point0.x + point1.x) / 2,
		Dy = (point0.x + point1.y) / 2;

	double x = ((Bx - Ax) * (Dx * Cy - Dy * Cx) - (Dx - Cx) * (Bx * Ay - By * Ax)) / ((By - Ay) * (Dx - Cx) - (Dy - Cy) * (Bx - Ax)) + position.x;

	double y = ((Dy - Cy) * (Bx * Ay - By * Ax) - (By - Ay) * (Dx * Cy - Dy * Cx)) / ((Dy - Cy) * (Bx - Ax) - (By - Ay) * (Dx - Cx)) + position.y;
	
	recuFiller(ims, color, x, y);

	text = sf::Texture();

	text.loadFromImage(ims);

	arr.setTexture(text);

	arr.setPosition(position);


	window->draw(arr);
}

void PrimitiveTriangle::translate(sf::Vector2f moveBy)
{
	isChanged = true;
	position = sf::Vector2f(position.x + moveBy.x, position.y + moveBy.y);
}

void PrimitiveTriangle::scale(float k)
{
	isChanged = true;
	point1 = sf::Vector2f(point1.x * k, point1.y * k);
	point2 = sf::Vector2f(point2.x * k, point2.y * k);
}

void PrimitiveTriangle::rotate(float rotation)
{
	isChanged = true;
	rotation = rotation * (M_PI / 180);
	point1 = sf::Vector2f(point1.x * std::cos(rotation) - point1.y * std::sin(rotation), point1.x * std::sin(rotation) + point1.y * std::cos(rotation));
	point2 = sf::Vector2f(point2.x * std::cos(rotation) - point2.y * std::sin(rotation), point2.x * std::sin(rotation) + point2.y * std::cos(rotation));
}
