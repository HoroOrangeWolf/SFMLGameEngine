#pragma once
#include "UpdateableObject.h"
#include "PrimitiveRectangle.h"
#include <SFML/Window.hpp>

class Player :
    public UpdateableObject,
    public PrimitiveRectangle
{
public:
    Player(sf::Vector2f widthHeight) :PrimitiveRectangle(sf::Vector2f(0.f, 0.f), widthHeight) {

    }
    void update();
};

