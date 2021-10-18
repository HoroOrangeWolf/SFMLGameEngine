#pragma once
#include <SFML/Graphics.hpp>
class KeyAndVector
{
public:
	enum sf::Keyboard::Key key;
	sf::Vector2f vector;


	KeyAndVector(sf::Vector2f vector,enum sf::Keyboard::Key key);

};

