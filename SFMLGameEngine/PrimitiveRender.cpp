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

void PrimitiveRender::drawLine(sf::Vector2f points0, sf::Vector2f points1, bool** tab)
{
	float xStart = points0.x;
	float yStart = points0.y;

	float xEnd = points1.x;
	float yEnd = points1.y;

	if (abs(xStart - xEnd) > abs(yStart - yEnd)) {
		float m = (yEnd - yStart) / (xEnd - xStart);

		float y = yStart;
		for (float i = xStart; i <= xEnd; i += 1.f) {

			tab[(int)i][(int)std::round(y)] = true;

			y += m;
		}
	}
	else {
		float m = abs(xEnd - xStart) / abs(yEnd - yStart);

		float y = xStart;
		for (float i = yStart; i <= yEnd; i += 1.f) {
			tab[(int)std::round(y)][(int)i] = true;
			y += m;
		}
	}
}


void PrimitiveRender::drawLine(sf::Vector2f points0, sf::Vector2f points1, sf::VertexArray& ar)
{
	float xStart = points0.x;
	float yStart = points0.y;

	float xEnd = points1.x;
	float yEnd = points1.y;

	if (abs(xStart - xEnd) > abs(yStart - yEnd)) {
		float m = (yEnd - yStart) / (xEnd - xStart);

		float y = yStart;
		for (float i = xStart; i <= xEnd; i += 1.f) {
			sf::Vertex vertex1;
			vertex1.position = sf::Vector2f(i, std::round(y));
			vertex1.color = sf::Color::Red;
			ar.append(vertex1);
			y += m;
		}
	}
	else {
		float m = abs(xEnd - xStart) / abs(yEnd - yStart);

		float y = xStart;
		for (float i = yStart; i <= yEnd; i += 1.f) {
			sf::Vertex vertex1;
			vertex1.position = sf::Vector2f(std::round(y), i);
			vertex1.color = sf::Color::Red;
			ar.append(vertex1);
			y += m;
		}
	}
}
