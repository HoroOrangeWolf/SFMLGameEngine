#pragma once
#include "DrawableObject.h"
#include <SFML/Graphics.hpp>

class LineSegment :
    public DrawableObject
{
private:
    sf::Vector2f point1, point2;
public:
    LineSegment(sf::Vector2f point1, sf::Vector2f point2);
    void getToDraw(sf::RenderWindow* window);
};

