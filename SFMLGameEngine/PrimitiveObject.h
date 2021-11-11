#pragma once
#include "PrimitiveRender.h"
#include <vector>
#include <SFML/Graphics.hpp>

class PrimitiveObject :
    public DrawableObject
{
private:
    std::vector<sf::Vector2f> pointList;
public:
    PrimitiveObject(std::vector<sf::Vector2f> pointList);
    void getToDraw(sf::RenderWindow* window);
};

