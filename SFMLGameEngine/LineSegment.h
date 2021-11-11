#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include <SFML/Graphics.hpp>

class LineSegment :
    public DrawableObject,
    public TransformableObject
{
private:
    sf::Vector2f point1, point2;
public:
    LineSegment(sf::Vector2f point1, sf::Vector2f point2);
    void getToDraw(sf::RenderWindow* window);
    void translate(sf::Vector2f moveBy);
    void scale(float k);
    void rotate(float rotation);
};

