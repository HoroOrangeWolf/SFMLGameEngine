#pragma once
#include <SFML/Graphics.hpp>
#include "DrawableObject.h"
#include "TransformableObject.h"

class PrimitiveArea: 
	public DrawableObject,
	public TransformableObject
{
private:
	float r = 0.f;
public:
	PrimitiveArea(sf::Vector2f position, float r);
	void getToDraw(sf::RenderWindow *window);
	void translate(sf::Vector2f moveBy);
	void scale(float k);
	void rotate(float rotation);


};

