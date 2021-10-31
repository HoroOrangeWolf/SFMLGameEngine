#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

#define M_PI 3.14159265358979323846

class PrimitiveRender
{

protected:
	bool isChanged = true;
	sf::Vector2f position;
	sf::Color color;
	sf::Image ims;
	sf::Texture text;
	void recuFiller(bool** elements, int x, int y);
public:
	PrimitiveRender();
	void setPosition(sf::Vector2f position);
	sf::Sprite arr;
	void drawLine(sf::Vector2f points0, sf::Vector2f points1, sf::Image& ar);
	virtual sf::Sprite& getToDraw() = 0;
};

