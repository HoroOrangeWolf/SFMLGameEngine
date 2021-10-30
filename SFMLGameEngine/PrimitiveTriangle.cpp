#include "PrimitiveTriangle.h"
#include <iostream>

PrimitiveTriangle::PrimitiveTriangle(sf::Vector2f position, sf::Vector2f widthHeight)
{
	this->position = position;

	this->point0 = sf::Vector2f(0.f, 0.f);
	this->point1 = sf::Vector2f(widthHeight.x, widthHeight.y);
	this->point2 = sf::Vector2f(0.f, widthHeight.y);
}

sf::VertexArray& PrimitiveTriangle::getToDraw()
{
	if (!isChanged)
		return arr;

	arr = sf::VertexArray();

	this->arr = sf::VertexArray();

	int width = std::abs(point0.x - point1.x) + 1;
	int height = std::abs(point0.y - point2.y) + 1;

	bool** buff = new bool *[width];

	for (int i = 0; i < width; ++i) {
		*(buff + i) = new bool[height] {false};
	}


	this->drawLine(point0, point2, buff);
	this->drawLine(point2, point1, buff);
	this->drawLine(point0, point1, buff);

	this->recuFiller(buff, width/4,  height - height*.2f);

	for (int x = 0, y; x < width; ++x) {
		bool *er = buff[x];
		
		for (y = 0; y < height; ++y) {
			if (er[y]) {
				arr.append(sf::Vertex(sf::Vector2f(position.x + x, position.y + y), sf::Color::Red));
			}
		}

	}

	for (int i = 0; i < width; ++i) {
		delete[] buff[i];
	}

	delete [] buff;

	return arr;
}
