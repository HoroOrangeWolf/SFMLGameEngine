#include "Player.h"
#include <iostream>

/**
 * .
 * \brief Aktualizuje kierunek poruszania sie gracza
 */
void Player::update()
{
	isStop = true;
	for (int i = 0; i < vectorList.size(); ++i) {
		KeyAndVector v1 = vectorList[i];
		if (sf::Keyboard::isKeyPressed(v1.key)) {
			position = sf::Vector2f(position.x + v1.vector.x, position.y + v1.vector.y);
			isStop = false;
			if (v1.vector.x > 0)
				direction = Direction::RIGHT;
			else if (v1.vector.x < 0)
				direction = Direction::LEFT;
			else if (v1.vector.y > 0)
				direction = Direction::DOWN;
			else if (v1.vector.y < 0)
				direction = Direction::UP;
		}
	}
}

/**
 * .
 * \brief Animuje postac gracza
 */
void Player::animate()
{
	countFPS++;

	if (isStop)
		return;

	if (countFPS >= intervalFPS) {
		imgIndex++;
		countFPS = 0;
	}

	switch (direction)
	{
	case Direction::DOWN:
	{
		if (imgIndex >= (framesFront.size() - 1))
			imgIndex = 0;

		currentTexture = sf::Texture();

		currentTexture.loadFromImage(framesFront[imgIndex]);

		currentSprite = sf::Sprite(currentTexture);
	}
	break;
	case Direction::UP:
	{
		if (imgIndex >= (framesBack.size() - 1))
			imgIndex = 0;

		currentTexture = sf::Texture();

		currentTexture.loadFromImage(framesBack[imgIndex]);

		currentSprite = sf::Sprite(currentTexture);
	}
	break;
	case Direction::LEFT:
	{
		if (imgIndex >= (framesLeft.size() - 1))
			imgIndex = 0;

		currentTexture = sf::Texture();

		currentTexture.loadFromImage(framesLeft[imgIndex]);

		currentSprite = sf::Sprite(currentTexture);
	}
	break;
	case Direction::RIGHT:
	{
		if (imgIndex >= (framesRight.size() - 1))
			imgIndex = 0;

		currentTexture = sf::Texture();

		currentTexture.loadFromImage(framesRight[imgIndex]);

		currentSprite = sf::Sprite(currentTexture);
	}
	break;
	default:
		break;
	}

	

	
}

/**
 * .
 * \brief Rysuje obiekt na mapie
 * \param window Wskaznik na okno
 */
void Player::getToDraw(sf::RenderWindow *window)
{
	currentSprite.setPosition(position);
	window->draw(currentSprite);
}
