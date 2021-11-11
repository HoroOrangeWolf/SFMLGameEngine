#pragma once
#include "PrimitiveRender.h"
class PrimitiveEllipse :
    public PrimitiveRender
{
private:
    double Rx, Ry;
public:
    PrimitiveEllipse(double Rx, double Ry);
    void getToDraw(sf::RenderWindow* window);

};

