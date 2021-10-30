#include "PrimitiveObject.h"

PrimitiveObject::PrimitiveObject(std::vector<sf::Vector2f> pointList)
{
	this->pointList = pointList;
}

sf::VertexArray& PrimitiveObject::getToDraw()
{
	sf::VertexArray arr;
	
	for (int i = 0; i < pointList.size() - 1; ++i) {
		sf::Vector2f& point_1 = pointList[i];
		sf::Vector2f& point_2 = pointList[i];
		this->drawLine(point_1, point_2, arr);
	}

	this->drawLine(pointList[0], pointList[pointList.size() - 1], arr);
	

	return arr;
}
