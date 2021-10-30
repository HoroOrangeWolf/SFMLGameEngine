#pragma once
#include "PrimitiveRender.h"
#include <list>
#include <SFML/Graphics.hpp>
class PrimitiveObject :
    public PrimitiveRender
{
private:
    std::list<sf::Vector2f> pointList;
    
};

