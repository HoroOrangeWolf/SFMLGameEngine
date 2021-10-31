#include "PrimitiveAreaFast.h"

PrimitiveAreaFast::PrimitiveAreaFast(float r)
{
    this->r = r;
}

PrimitiveAreaFast::PrimitiveAreaFast(sf::Color color, float r)
{
    this->r = r;
    this->color = color;
}

sf::VertexArray& PrimitiveAreaFast::getToDraw()
{
    if (!isChanged)
        return arr;

    isChanged = false;

    arr = sf::VertexArray();

	float step = 1.f / this->r;

	float xc = position.x;
	float yc = position.y;


	float value = 0;

	for (; value < (M_PI/2); value += step)
	{
		sf::Vertex vertex;
		double x = (double)r * cos(value) + 0.5;
		double y = (double)r * sin(value) + 0.5;

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
