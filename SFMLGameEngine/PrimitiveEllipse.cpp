#include "PrimitiveEllipse.h"


PrimitiveEllipse::PrimitiveEllipse(double Rx, double Ry) {
	this->Rx = Rx;
	this->Ry = Ry;
}

sf::VertexArray& PrimitiveEllipse::getToDraw()
{
	if (!isChanged)
		return arr;

	isChanged = false;

	arr = sf::VertexArray();

	float step = 1.f / this->Rx;

	float xc = position.x ;
	float yc = position.y;


	float value = 0;

	for (; value < (M_PI / 2); value += step)
	{
		sf::Vertex vertex;
		double x = (double)Rx * cos(value) + 0.5;
		double y = (double)Ry * sin(value) + 0.5;

		vertex.color = sf::Color::Red;
		vertex.position = sf::Vector2f((xc + x), yc + y);

		arr.append(vertex);

		vertex.color = sf::Color::Red;
		vertex.position = sf::Vector2f((xc - x), (yc + y));

		arr.append(vertex);


		vertex.color = sf::Color::Red;
		vertex.position = sf::Vector2f((xc + x), (yc - y));

		arr.append(vertex);

		vertex.color = sf::Color::Red;
		vertex.position = sf::Vector2f((xc - x), (yc - y));

		arr.append(vertex);

	}


	return arr;
}
