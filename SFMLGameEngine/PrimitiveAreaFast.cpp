#include "PrimitiveAreaFast.h"

/**
 * .
 * \brief Konstruktor
 * \param r Promien
 */
PrimitiveAreaFast::PrimitiveAreaFast(float r)
{
    this->r = r;
}

/**
 * .
 * \brief Konstruktor
 * \param color Kolor
 * \param r Promien
 */
PrimitiveAreaFast::PrimitiveAreaFast(sf::Color color, float r)
{
    this->r = r;
    this->color = color;
}

/**
 * .
 * \brief Rysowanie szybkiego okregu
 * \param window Wskaznik na okno
 */
void PrimitiveAreaFast::getToDraw(sf::RenderWindow* window)
{
	if (!isChanged)
	{
		window->draw(arr);
		return;
	}

	isChanged = false;

	ims = sf::Image();

	ims.create(window->getSize().x, window->getSize().y, sf::Color::Transparent);

	float step = 1.f / this->r;

	float xc = r + position.x;
	float yc = r + position.y;

	float value = 0;

	for (; value < (M_PI/2); value += step)
	{
		double x = (double)r * cos(value) + 0.5;
		double y = (double)r * sin(value) + 0.5;

		putPixel((xc + x), (yc + y), color);
		putPixel((xc - x), (yc + y), color);
		putPixel((xc + x), (yc - y), color);
		putPixel((xc - x), (yc - y), color);
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
void PrimitiveAreaFast::translate(sf::Vector2f moveBy)
{
	isChanged = true;
	position = sf::Vector2f(position.x + moveBy.x, position.y + moveBy.y);
}

/**
 * .
 * \brief Skalowanie
 * \param k Wspolczynnik skalowania
 */
void PrimitiveAreaFast::scale(float k)
{
	isChanged = true;
	r = std::abs(k * r);
}

/**
 * .
 * \brief Rotacja
 * \param rotation Wspolczynnik rotacji
 */
void PrimitiveAreaFast::rotate(float rotation)
{
}