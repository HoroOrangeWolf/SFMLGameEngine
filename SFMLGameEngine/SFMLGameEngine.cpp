#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "KeyAndVector.h"
#include "Moveable.h"

int main()
{
    Engine engine("title", 800, 800);
    engine.setBackgroundColor(sf::Color::Green);

    MoveableBlock player(sf::Vector2f(100.f, 200.f));

    player.addKeyAndVector(KeyAndVector(sf::Vector2f(0.f, -1.f), sf::Keyboard::W));
    player.addKeyAndVector(KeyAndVector(sf::Vector2f(-1.f, 0.f), sf::Keyboard::A));
    player.addKeyAndVector(KeyAndVector(sf::Vector2f(0.f, 1.f), sf::Keyboard::S));
    player.addKeyAndVector(KeyAndVector(sf::Vector2f(1.f, 0.f), sf::Keyboard::D));

    player.setFillColor(sf::Color::Blue);
   
    engine.addMoveableBlock(player);

    engine.run();
    

    return 0;
}