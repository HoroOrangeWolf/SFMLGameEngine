#include "PrimitiveObject.h"
#include <iostream>

PrimitiveObject::PrimitiveObject(std::vector<sf::Vector2f> pointList)
{
	this->pointList = pointList;
}

void PrimitiveObject::getToDraw(sf::RenderWindow* window)
{
	if (!isChanged)
	{
		window->draw(arr);
		return;
	}

	isChanged = false;

	ims = sf::Image();

	double width=0;
	double height=0;

	for (int i = 0; i < pointList.size(); ++i)
	{
		sf::Vector2f& buff = pointList[i];
		if (buff.x > width)
			width = buff.x;

		if (buff.y > height)
			height = buff.y;
	}

	ims.create(width + 1, height + 1, sf::Color::Transparent);
	
	for (int i = 0; i < pointList.size() - 1; ++i) {
		sf::Vector2f& point_1 = pointList[i];
		sf::Vector2f& point_2 = pointList[i + 1];
		this->drawLine(sf::Vector2f(point_1.x + position.x, point_1.y + position.y), sf::Vector2f(point_2.x + position.x, point_2.y + position.y), ims);
	}
	sf::Vector2f& point_1 = pointList[pointList.size() - 1];
	sf::Vector2f& point_2 = pointList[0];

	this->drawLine(sf::Vector2f(point_1.x + position.x, point_1.y + position.y), sf::Vector2f(point_2.x + position.x, point_2.y + position.y), ims);

	evenFiller(ims, color, width + 1, height + 1);

	text = sf::Texture();

	text.loadFromImage(ims);

	arr.setTexture(text);

	arr.setPosition(sf::Vector2f(0.f, 0.f));


	window->draw(arr);
}
