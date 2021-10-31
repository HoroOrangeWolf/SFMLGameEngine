#include "PrimitiveRender.h"
#include <iostream>

void PrimitiveRender::recuFiller(sf::Image& image, sf::Color& color, int x, int y)
{
	if (image.getPixel(x, y) == color)
		return;

	image.setPixel(x, y, color);

	recuFiller(image, color, x + 1, y);
	recuFiller(image, color, x - 1, y);
	recuFiller(image, color, x, y + 1);
	recuFiller(image, color, x, y - 1);
}


void PrimitiveRender::setPosition(sf::Vector2f position)
{
	this->position = position;
	this->color = sf::Color::Red;
}

void PrimitiveRender::evenFiller(sf::Image& image, sf::Color& color, int width, int height)
{
	for (int y = 0; y < height; y++)
		for (int x = 0, pars = 0; x < width; x++)
			if (image.getPixel(x, y) == color)
			{
				pars++;
				for (x+=1; x < width && image.getPixel(x, y) == color; ++x);

				for (; x < width && image.getPixel(x, y) == sf::Color::Transparent; ++x)
					if(pars%2==1)
						image.setPixel(x, y, color);

				for (; x < width && image.getPixel(x, y) == color; ++x);

				pars++;

			}

}

PrimitiveRender::PrimitiveRender()
{
	this->position = sf::Vector2f(0.f, 0.f);
}

void PrimitiveRender::setColor(sf::Color color)
{
	this->color = color;
}

void PrimitiveRender::drawLine(sf::Vector2f points0, sf::Vector2f points1, sf::Image& ar)
{
	double xStart = points0.x;
	double yStart = points0.y;

	double xEnd = points1.x;
	double yEnd = points1.y;


	if (abs(xStart - xEnd) > abs(yStart - yEnd)) {

		if (points0.x > points1.x) {
			xStart = points1.x;
			xEnd = points0.x;

			yStart = points1.x;
			yEnd = points0.y;
		}

		double m = (yEnd - yStart) / (xEnd - xStart);

		double y = yStart;
		for (double i = xStart; i <= xEnd; i += 1.f) {
			ar.setPixel(i, std::round(y), color);
			y += m;
		}
	}
	else {

		if (points0.y > points1.y) {
			xStart = points1.x;
			xEnd = points0.x;

			yStart = points1.x;
			yEnd = points0.y;
		}

		double m = (xEnd - xStart) / (yEnd - yStart);

		double y = xStart;
		for (double i = yStart; i <= yEnd; i += 1.f) {

			ar.setPixel(std::round(y), i, color);

			y += m;
		}
	}
}
