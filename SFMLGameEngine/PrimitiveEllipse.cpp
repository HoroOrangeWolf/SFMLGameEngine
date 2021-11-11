#include "PrimitiveEllipse.h"


PrimitiveEllipse::PrimitiveEllipse(double Rx, double Ry) {
	this->Rx = Rx;
	this->Ry = Ry;
}

void PrimitiveEllipse::getToDraw(sf::RenderWindow* window)
{
	if (!isChanged)
	{
		window->draw(arr);
		return;
	}

	isChanged = false;

	arr = sf::Sprite();

	ims = sf::Image();

	ims.create(Rx * 2 + 1, Ry * 2 + 1, sf::Color::Transparent);

	float step = 1.f / std::max(this->Rx, this->Ry);

	float xc = Rx;
	float yc = Ry;


	float value = 0;

	for (; value < (M_PI / 2); value += step)
	{

		int x = std::floor((double)Rx * cos(value));
		int y = std::floor((double)Ry * sin(value));


		ims.setPixel(xc + x, yc + y, color);

		ims.setPixel(xc - x, yc + y, color);

		ims.setPixel(xc + x, yc - y, color);

		ims.setPixel(xc - x, yc - y, color);

	}

	text = sf::Texture();

	text.loadFromImage(ims);

	arr.setTexture(text);

	arr.setPosition(position);

	window->draw(arr);
}
