#pragma once
#include "DrawableObject.h"
class PrimitiveEllipse :
    public DrawableObject
{
private:
    double Rx, Ry;
    double rotation = 0;
public:
    PrimitiveEllipse(double Rx, double Ry);
    void getToDraw(sf::RenderWindow* window);
    void translate(sf::Vector2f moveBy);
    void scale(float k);
    void rotate(float rotation);
};

