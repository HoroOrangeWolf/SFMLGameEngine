#pragma once
#include <SFML/Graphics.hpp>
class KeyAndVector
{
public:
	sf::Keyboard::Key key;
	sf::Vector2f vector;


	KeyAndVector(sf::Vector2f vector, sf::Keyboard::Key key);

};

