#include "PrimitiveEllipse.h"
#include <iostream>

/**
 * .
 * \brief Konstruktor
 * \param Rx Promien X
 * \param Ry Promien Y
*/
PrimitiveEllipse::PrimitiveEllipse(double Rx, double Ry) {
	this->Rx = Rx;
	this->Ry = Ry;
}

/**
 * .
 * \brief Rysowanie elipsy
 * \param window Wskaznik na okno
 */
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

	float xc = position.x;
	float yc = position.y;


	float value = 0;
	int xBuff, yBuff;
	int xBuff2, yBuff2;


		
	for (; value < (M_PI / 2); value += step)
	{

		int x = std::floor((double)Rx * cos(value));
		int y = std::floor((double)Ry * sin(value));

		xBuff = xc + x;
		yBuff = yc + y;

		

		xBuff2 = xc + (xBuff - xc) * std::cos(rotation) - (yBuff - yc) * std::sin(rotation);
		yBuff2 = yc + (xBuff - xc) * std::sin(rotation) + (yBuff - yc) * std::cos(rotation);

		putPixel(xBuff2, yBuff2, color);

		putPixel(xBuff2 + 1, yBuff2, color);
		putPixel(xBuff2 + 1, yBuff2 + 1, color);
		putPixel(xBuff2, yBuff2 + 1, color);
		putPixel(xBuff2 - 1, yBuff2 + 1, color);
		putPixel(xBuff2 - 1, yBuff2, color);
		putPixel(xBuff2 - 1, yBuff2 - 1, color);
		putPixel(xBuff2, yBuff2 - 1, color);
		putPixel(xBuff2 + 1, yBuff2 - 1, color);

		xBuff = xc - x;
		yBuff = yc + y;

		xBuff2 = xc + (xBuff - xc) * std::cos(rotation) - (yBuff - yc) * std::sin(rotation);
		yBuff2 = yc + (xBuff - xc) * std::sin(rotation) + (yBuff - yc) * std::cos(rotation);

		putPixel(xBuff2, yBuff2, color);

		putPixel(xBuff2 + 1, yBuff2, color);
		putPixel(xBuff2 + 1, yBuff2 + 1, color);
		putPixel(xBuff2, yBuff2 + 1, color);
		putPixel(xBuff2 - 1, yBuff2 + 1, color);
		putPixel(xBuff2 - 1, yBuff2, color);
		putPixel(xBuff2 - 1, yBuff2 - 1, color);
		putPixel(xBuff2, yBuff2 - 1, color);
		putPixel(xBuff2 + 1, yBuff2 - 1, color);

		xBuff = xc + x;
		yBuff = yc - y;

		xBuff2 = xc + (xBuff - xc) * std::cos(rotation) - (yBuff - yc) * std::sin(rotation);
		yBuff2 = yc + (xBuff - xc) * std::sin(rotation) + (yBuff - yc) * std::cos(rotation);

		putPixel(xBuff2, yBuff2, color);

		putPixel(xBuff2 + 1, yBuff2, color);
		putPixel(xBuff2 + 1, yBuff2 + 1, color);
		putPixel(xBuff2, yBuff2 + 1, color);
		putPixel(xBuff2 - 1, yBuff2 + 1, color);
		putPixel(xBuff2 - 1, yBuff2, color);
		putPixel(xBuff2 - 1, yBuff2 - 1, color);
		putPixel(xBuff2, yBuff2 - 1, color);
		putPixel(xBuff2 + 1, yBuff2 - 1, color);

		xBuff = xc - x;
		yBuff = yc - y;

		xBuff2 = xc + (xBuff - xc) * std::cos(rotation) - (yBuff - yc) * std::sin(rotation);
		yBuff2 = yc + (xBuff - xc) * std::sin(rotation) + (yBuff - yc) * std::cos(rotation);

		putPixel(xBuff2, yBuff2, color);

		putPixel(xBuff2 + 1, yBuff2, color);
		putPixel(xBuff2 + 1, yBuff2 + 1, color);
		putPixel(xBuff2, yBuff2 + 1, color);
		putPixel(xBuff2 - 1, yBuff2 + 1, color);
		putPixel(xBuff2 - 1, yBuff2, color);
		putPixel(xBuff2 - 1, yBuff2 - 1, color);
		putPixel(xBuff2, yBuff2 - 1, color);
		putPixel(xBuff2 + 1, yBuff2 - 1, color);
	}

	recuFiller(ims, color, (int)xc, (int)yc);

	text = sf::Texture();

	text.loadFromImage(ims);

	arr.setTexture(text);

	arr.setPosition(sf::Vector2f(0.f, 0.f));

	window->draw(arr);
}

/**
 * .
 * \brief Przesuniecie
 * \param moveBy Wektor przesuniecia
 */
void PrimitiveEllipse::translate(sf::Vector2f moveBy)
{
	isChanged = true;
	position = sf::Vector2f(position.x + moveBy.x, position.y + moveBy.y);
}

/**
 * .
 * \brief Skalowanie
 * \param k Wspolczynnik skalowania
 */
void PrimitiveEllipse::scale(float k)
{
	isChanged = true;
	Rx = std::abs(Rx * k);
	Ry = std::abs(Ry * k);
}

/**
 * .
 * \brief Rotacja
 * \param rot Wspolczynnik rotacji
 */
void PrimitiveEllipse::rotate(float rot)
{
	this->rotation += rot * (M_PI / 180);;
	isChanged = true;
}