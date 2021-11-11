#pragma once
#include "DrawableObject.h"
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
    void translate(sf::Vector2f moveBy);
    void scale(float k);
    void rotate(float rotation);
};

