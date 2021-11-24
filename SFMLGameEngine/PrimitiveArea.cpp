#include "PrimitiveArea.h"
#include <cmath>

/**
 * .
 * \brief Konstruktor
 * \param position
 * \param r
 */
PrimitiveArea::PrimitiveArea(sf::Vector2f position, float r)
{
	this->position = position;
	this->r = r;
}

/**
 * .
 * \brief Rysowanie okregu
 * \param window Wskaznik na okno
 */
void PrimitiveArea::getToDraw(sf::RenderWindow* window)
{
	if (!isChanged)
	{
		window->draw(arr);
		return;
	}

	isChanged = false;

	ims= sf::Image();

	ims.create(window->getSize().x, window->getSize().y, sf::Color::Transparent);

	float step = 1.f / this->r;

	float xc = r + position.x;
	float yc = r + position.y;

	float value = 0;

	for (value; value < 2 * M_PI; value += step)
	{
		sf::Vertex vertex;
		vertex.position = sf::Vector2f(round(xc + (double)r * cos(value) + 0.5), round(yc + (double)r * sin(value) + 0.5));

		int x1 = vertex.position.x, y1 = vertex.position.y;

		putPixel(x1, y1, color);

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
void PrimitiveArea::translate(sf::Vector2f moveBy)
{
	isChanged = true;
	position = sf::Vector2f(position.x + moveBy.x, position.y + moveBy.y);
}

/**
 * .
 * \brief Skalowanie
 * \param k Wspolczynnik skalowania
 */
void PrimitiveArea::scale(float k)
{
	isChanged = true;
	r = std::abs(r * k);
}

/**
 * .
 * \brief Rotacja
 * \param rotation Wspolczynnik rotacji
 */
void PrimitiveArea::rotate(float rotation)
{
}


