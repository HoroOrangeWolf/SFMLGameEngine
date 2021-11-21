#include "BitmapHandler.h"
#include <iostream>

sf::Image BitmapHandler::create(int width, int height)
{
	sf::Image ims = sf::Image();

	ims.create(width, height, sf::Color::Transparent);

	return ims;
}

void BitmapHandler::save(sf::Image& ims, std::string path)
{
	ims.saveToFile(path);
}

sf::Image BitmapHandler::getImageFromFile(std::string path)
{
	sf::Texture texture;

	texture.loadFromFile(path);

	return texture.copyToImage();
}

void BitmapHandler::copyTo(sf::Image& from, sf::Image& to, int destinationX, int destinationY)
{
	to.copy(from, destinationX, destinationY);
}
