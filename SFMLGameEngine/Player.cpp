#include "Player.h"
#include <iostream>

void Player::update()
{
	for (int i = 0; i < vectorList.size(); ++i) {
		KeyAndVector v1 = vectorList[i];
		if (sf::Keyboard::isKeyPressed(v1.key)) {
			position = sf::Vector2f(position.x + v1.vector.x, position.y + v1.vector.y);
		}
	}
}

void Player::animate()
{
	countFPS++;

	if (countFPS >= intervalFPS) {
		imgIndex++;
		countFPS = 0;
	}

	if (imgIndex >= (frames.size() - 1))
		imgIndex = 0;

	currentTexture = sf::Texture();

	currentTexture.loadFromImage(frames[imgIndex]);

	currentSprite = sf::Sprite(currentTexture);
}

void Player::getToDraw(sf::RenderWindow *window)
{
	currentSprite.setPosition(position);
	window->draw(currentSprite);
}
