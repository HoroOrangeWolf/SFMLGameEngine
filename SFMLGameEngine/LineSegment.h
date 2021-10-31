#pragma once
#include "PrimitiveRender.h"
#include <SFML/Graphics.hpp>

class LineSegment :
    public PrimitiveRender
{
private:
    sf::Vector2f point1, point2;
public:
    LineSegment(sf::Vector2f point1, sf::Vector2f point2);
    sf::Sprite& getToDraw();
};

