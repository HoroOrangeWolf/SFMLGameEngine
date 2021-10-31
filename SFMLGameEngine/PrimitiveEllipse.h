#pragma once
#include "PrimitiveRender.h"
class PrimitiveEllipse :
    public PrimitiveRender
{
private:
    double Rx, Ry;
public:
    PrimitiveEllipse(double Rx, double Ry);
    sf::Sprite& getToDraw();

};

