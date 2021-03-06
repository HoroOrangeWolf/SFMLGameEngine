#include "DrawableObject.h"
#include <iostream>

/**
 * .
 * \brief Wypelnianie rekurencyjne
 * \param image Obraz
 * \param color Kolor wypelnienia
 * \param x Pozycja X
 * \param y Pozycja Y
 */
void DrawableObject::recuFiller(sf::Image& image, sf::Color& color, int x, int y)
{
	if (image.getPixel(x, y) == color)
		return;

	putPixel(x, y, color);

	recuFiller(image, color, x + 1, y);
	recuFiller(image, color, x - 1, y);
	recuFiller(image, color, x, y + 1);
	recuFiller(image, color, x, y - 1);
}

/**
 * .
 * \brief Ustawianie pozycji obiektu
 * \param position Pozycja obiektu
 */
void DrawableObject::setPosition(sf::Vector2f position)
{
	this->position = position;
}

/**
 * .
 * \brief Wstawia pixel na bitmape
 * \param x Pozycja X
 * \param y Pozycja Y
 * \param color Kolor
 */
void DrawableObject::putPixel(int x, int y, sf::Color color)
{
	if (x >= 0 && x < ims.getSize().x && y >= 0 && y < ims.getSize().y)
		ims.setPixel(x, y, color);
}

/**
 * .
 * \brief Wypelnia obiekt
 * \param image Bitmapa
 * \param color Kolor
 * \param width Szerokosc
 * \param height Wysokosc
 */
void DrawableObject::evenFiller(sf::Image& image, sf::Color& color, int width, int height)
{
	for (int y = 0; y < height; y++)
		for (int x = 0, pars = 0, xBuff; x < width; x++)
			if (image.getPixel(x, y) == color)
			{
				pars++;
				for (x+=1; x < width && image.getPixel(x, y) == color; ++x);

				if (pars % 2 == 1) {

					xBuff = x;

					for (; xBuff < width && image.getPixel(xBuff, y) == sf::Color::Transparent; ++xBuff);

					if (xBuff == width)
						break;

					for (; x < width && image.getPixel(x, y) == sf::Color::Transparent; ++x)
						putPixel(x, y, color);
				}
				else
					for (; x < width && image.getPixel(x, y) == sf::Color::Transparent; ++x);

				for (; x < width && image.getPixel(x, y) == color; ++x);

				pars++;

			}

}

/**
 * .
 * \brief Ustawia wartosci poczatkowe
 */
DrawableObject::DrawableObject()
{
	this->position = sf::Vector2f(0.f, 0.f);
	isChanged = true;
}

/**
 * .
 * \brief Ustawia kolor
 * \param color Kolor
 */
void DrawableObject::setColor(sf::Color color)
{
	this->color = color;
}

/**
 * .
 * \brief Rysuje linie
 * \param points0 Poczatek linii
 * \param points1 Koniec linii
 * \param ar Bitmapa
 */
void DrawableObject::drawLine(sf::Vector2f points0, sf::Vector2f points1, sf::Image& ar)
{
	double xStart = points0.x;
	double yStart = points0.y;

	double xEnd = points1.x;
	double yEnd = points1.y;


	if (abs(xStart - xEnd) > abs(yStart - yEnd)) {

		
	
 
		if (points0.x > points1.x) {
			xStart = points1.x;
			xEnd = points0.x;

			yStart = points1.y;
			yEnd = points0.y;
		}

		double m = (yEnd - yStart) / (xEnd - xStart);

		double y = yStart;
		int x1, y1;
		for (double i = xStart; i <= xEnd; i += 1.f) {
			x1 = (int)i;
			y1 = std::round(y);

			putPixel(x1, y1, color);

			putPixel(x1 + 1, y1, color);
			putPixel(x1 + 1, y1 + 1, color);
			putPixel(x1, y1 + 1, color);
			putPixel(x1 - 1, y1 + 1, color);
			putPixel(x1 - 1, y1, color);
			putPixel(x1 - 1, y1 - 1, color);
			putPixel(x1, y1 - 1, color);
			putPixel(x1 + 1, y1 - 1, color);


			y += m;
		}
	}
	else {

		if (points0.y > points1.y) {
			xStart = points1.x;
			xEnd = points0.x;

			yStart = points1.y;
			yEnd = points0.y;
		}

		double m = (xEnd - xStart) / (yEnd - yStart);

		double y = xStart;
		int x1, y1;
		for (double i = yStart; i <= yEnd; i += 1.f) {

			x1 = std::round(y);
			y1 = (int)i;

			putPixel(x1, y1, color);

			putPixel(x1 + 1, y1, color);
			putPixel(x1 + 1, y1 + 1, color);
			putPixel(x1, y1 + 1, color);
			putPixel(x1 - 1, y1 + 1, color);
			putPixel(x1 - 1, y1, color);
			putPixel(x1 - 1, y1 - 1, color);
			putPixel(x1, y1 - 1, color);
			putPixel(x1 + 1, y1 - 1, color);


			y += m;
		}
	}
}
