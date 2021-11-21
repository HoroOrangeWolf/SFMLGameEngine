#include "BitmapHandler.h"

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
	sf::Image ims = sf::Image();

	ims.loadFromFile(path);

	return ims;
}

void BitmapHandler::copyTo(sf::Image& from, sf::Image& to, int destinationX, int destinationY)
{
	to.copy(from, destinationX, destinationY);
}
