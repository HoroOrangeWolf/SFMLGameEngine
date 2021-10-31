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

sf::Sprite& PrimitiveAreaFast::getToDraw()
{
    if (!isChanged)
        return arr;

    isChanged = false;

    sf::Image im = sf::Image();

	im.create(r*2 + 1, r*2+1);

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


    return arr;

}
