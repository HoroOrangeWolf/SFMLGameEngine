#pragma once
#include "PrimitiveRender.h"
class PrimitiveEllipse :
    public DrawableObject
{
private:
    double Rx, Ry;
public:
    PrimitiveEllipse(double Rx, double Ry);
    void getToDraw(sf::RenderWindow* window);

};

