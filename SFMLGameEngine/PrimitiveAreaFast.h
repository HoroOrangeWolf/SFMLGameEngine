#pragma once
#include "DrawableObject.h"
#include <SFML/Graphics.hpp>

class PrimitiveAreaFast :
    public DrawableObject
{
private:
    float r;
    sf::Color color = sf::Color::Red;

public:
    PrimitiveAreaFast(float r);
    PrimitiveAreaFast(sf::Color color, float r);
    void getToDraw(sf::RenderWindow* window);
    void translate(sf::Vector2f moveBy);
    void scale(float k);
    void rotate(float rotation);
};

