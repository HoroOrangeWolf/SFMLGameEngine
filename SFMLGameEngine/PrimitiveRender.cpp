#include "PrimitiveRender.h"

void PrimitiveRender::recuFiller(bool** elements, int x, int y)
{
	bool element = elements[x][y];
	if (element)
		return;

	elements[x][y] = true;

	recuFiller(elements, x + 1, y);
	recuFiller(elements, x - 1, y);
	recuFiller(elements, x, y + 1);
	recuFiller(elements, x, y - 1);
}


void PrimitiveRender::setPosition(sf::Vector2f position)
{
	this->position = position;
	this->color = sf::Color::Red;
}

PrimitiveRender::PrimitiveRender()
{
	this->position = sf::Vector2f(0.f, 0.f);
}

void PrimitiveRender::drawLine(sf::Vector2f points0, sf::Vector2f points1, sf::Image& ar)
{
	float xStart = std::min(points0.x, points1.x);
	float yStart = std::min(points0.y, points1.y);

	float xEnd = std::max(points0.x, points1.x);
	float yEnd = std::max(points0.y, points1.y);

	if (abs(xStart - xEnd) > abs(yStart - yEnd)) {
		float m = (yEnd - yStart) / (xEnd - xStart);

		float y = yStart;
		for (float i = xStart; i <= xEnd; i += 1.f) {
			ar.setPixel(i, std::round(y), color);
			y += m;
		}
	}
	else {
		float m = abs(xEnd - xStart) / abs(yEnd - yStart);

		float y = xStart;
		for (float i = yStart; i <= yEnd; i += 1.f) {

			ar.setPixel(std::round(y), i, color);
			y += m;
		}
	}
}
