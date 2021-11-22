#pragma once
#include "UpdateableObject.h"
#include "PrimitiveRectangle.h"
#include "SpriteObject.h"
#include <SFML/Window.hpp>

enum class Direction {LEFT, RIGHT, UP, DOWN};

class Player :
    public UpdateableObject,
    public SpriteObject
{
private:
    sf::Vector2f widthHeight;
    sf::Vector2f position;
    Direction direction = Direction::RIGHT;
    
public:
    Player(sf::Vector2f widthHeight) {
        this->widthHeight = widthHeight;
        this->position = sf::Vector2f(0.f, 0.f);
    }
    void update();
    void animate() override;
    void getToDraw(sf::RenderWindow *window);
};

