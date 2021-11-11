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

void PrimitiveAreaFast::getToDraw(sf::RenderWindow* window)
{
	if (!isChanged)
	{
		window->draw(arr);
		return;
	}

    isChanged = false;

    sf::Image im = sf::Image();

	im.create(window->getSize().x, window->getSize().y);

	float step = 1.f / this->r;

	float xc = r;
	float yc = r;


	float value = 0;

	for (; value < (M_PI/2); value += step)
	{
		double x = (double)r * cos(value) + 0.5;
		double y = (double)r * sin(value) + 0.5;

		im.setPixel((xc + x), (yc + y), color);

		im.setPixel((xc - x), (yc + y), color);

		im.setPixel((xc + x), (yc - y), color);

		im.setPixel((xc - x), (yc - y), color);

	}

	text = sf::Texture();

	text.loadFromImage(ims);

	arr.setTexture(text);

	arr.setPosition(position);


	window->draw(arr);
}
