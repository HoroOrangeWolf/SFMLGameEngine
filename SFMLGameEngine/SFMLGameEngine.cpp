#include <SFML/Graphics.hpp>
#include <iostream>

#include "Engine.h"
#include "KeyAndVector.h"
#include "BitmapHandler.h"

int main()
{
    Engine engine("title", 800, 800);
    //Engine engine(sf::VideoMode(800, 800), "title", sf::Style::Fullscreen);

    engine.setBackgroundColor(sf::Color::Black);

    engine.run();
   
    return 0;
}