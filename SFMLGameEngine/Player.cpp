#include "Player.h"

void Player::update()
{
	for (int i = 0; i < vectorList.size(); ++i) {
		KeyAndVector v1 = vectorList[i];
		if (sf::Keyboard::isKeyPressed(v1.key)) {
			isChanged = true;
			position = sf::Vector2f(position.x + v1.vector.x, position.y + v1.vector.y);
		}
	}
}
