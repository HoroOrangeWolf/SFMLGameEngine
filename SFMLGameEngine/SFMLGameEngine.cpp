#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "KeyAndVector.h"

int main()
{
    Engine engine("title", 800, 800);
    engine.setBackgroundColor(sf::Color::Black);

  

    engine.run();
    

    return 0;
}