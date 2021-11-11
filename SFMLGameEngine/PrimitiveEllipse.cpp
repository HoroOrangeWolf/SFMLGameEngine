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

	ims.create(window->getSize().x,  window->getSize().y, sf::Color::Transparent);

	float step = 1.f / std::max(this->Rx, this->Ry);

	float xc = Rx + position.x;
	float yc = Ry + position.y;


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

	arr.setPosition(sf::Vector2f(0.f, 0.f));

	window->draw(arr);
}
