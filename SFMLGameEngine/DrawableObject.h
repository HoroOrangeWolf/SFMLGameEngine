#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

#define M_PI 3.14159265358979323846

class DrawableObject
{

protected:
	bool isChanged = true;
	sf::Vector2f position;
	sf::Color color;
	sf::Image ims;
	sf::Texture text;
	void recuFiller(sf::Image& image, sf::Color& color, int x, int y);
	void evenFiller(sf::Image& image, sf::Color& color, int width, int height);
public:
	DrawableObject();
	void setPosition(sf::Vector2f position);
	void putPixel(int x, int y, sf::Color color);
	sf::Sprite arr;
	void drawLine(sf::Vector2f points0, sf::Vector2f points1, sf::Image& ar);
	void setColor(sf::Color color);
	virtual void getToDraw(sf::RenderWindow *window) = 0;
};

