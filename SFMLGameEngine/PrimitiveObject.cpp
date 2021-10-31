#include "PrimitiveObject.h"
#include <iostream>

PrimitiveObject::PrimitiveObject(std::vector<sf::Vector2f> pointList)
{
	this->pointList = pointList;
}

sf::Sprite& PrimitiveObject::getToDraw()
{
	if (!isChanged)
		return arr;

	isChanged = false;

	ims = sf::Image();

	double width=0;
	double height=0;

	for (int i = 0; i < pointList.size(); ++i)
	{
		sf::Vector2f& buff = pointList[i];
		if (buff.x > width)
			width = buff.x;

		if (buff.y > width)
			height = buff.y;
	}

	ims.create(width + 1, height + 1, sf::Color::Transparent);
	
	for (int i = 0; i < pointList.size() - 1; ++i) {
		sf::Vector2f& point_1 = pointList[i];
		sf::Vector2f& point_2 = pointList[i + 1];
		this->drawLine(point_1, point_2, ims);
		std::cout << "XD";
	}

	this->drawLine(pointList[0], pointList[pointList.size() - 1], ims);


	text = sf::Texture();

	text.loadFromImage(ims);

	arr.setTexture(text);

	arr.setPosition(position);


	return arr;
}
