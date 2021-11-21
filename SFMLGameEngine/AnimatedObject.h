#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class AnimatedObject
{
protected:
	int intervalFPS = 6;
	int countFPS = 0;
	int imgIndex = 0;
	bool isStop = false;
	std::vector<sf::Image> frames;
	
public:
	void setFrames(sf::Image arr[], int length);
	void addFrame(sf::Image img);
	void clearFrames();
	void setIntervalFPS(int fps);
	int getIntervalFPS();
	void setIsStop(bool isStop);
	bool getIsStop();
	virtual void animate() = 0;
};

