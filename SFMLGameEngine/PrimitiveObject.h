#pragma once
#include "PrimitiveRender.h"
#include <vector>
#include <SFML/Graphics.hpp>

class PrimitiveObject :
    public PrimitiveRender
{
private:
    std::vector<sf::Vector2f> pointList;
public:
    PrimitiveObject(std::vector<sf::Vector2f> pointList);
    sf::Sprite& getToDraw();
};

