#include "KeyAndVector.h"

/**
 * .
 * \brief Konstruktor
 * \param vector Przesuniecie po nacisnieciu przycisku
 * \param Definicja klawiszy sluzacych do poruszania
 */
KeyAndVector::KeyAndVector(sf::Vector2f vector,enum sf::Keyboard::Key key)
{
	this->vector = vector;
	this->key = key;
}
