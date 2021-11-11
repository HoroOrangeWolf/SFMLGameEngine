#pragma once
#include "PrimitiveRender.h"
#include <SFML/Graphics.hpp>

class PrimitiveAreaFast :
    public PrimitiveRender
{
private:
    float r;
    sf::Color color = sf::Color::Red;

public:
    PrimitiveAreaFast(float r);
    PrimitiveAreaFast(sf::Color color, float r);
    void getToDraw(sf::RenderWindow* window);
};

