#pragma once
#include <SFML/Graphics.hpp>
#include "PrimitiveRender.h"

class PrimitiveArea: public PrimitiveRender
{
private:
	float r = 0.f;
public:
	PrimitiveArea(sf::Vector2f position, float r);
	void getToDraw(sf::RenderWindow *window);
};

