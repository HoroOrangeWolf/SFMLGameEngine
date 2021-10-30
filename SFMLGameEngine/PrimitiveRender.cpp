#include "PrimitiveRender.h"

void PrimitiveRender::fillPrimitive(bool** elements, int width, int height)
{
	
}

void PrimitiveRender::recuFiller(bool** elements, int x, int y, int width, int height)
{
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
