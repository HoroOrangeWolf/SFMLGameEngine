#include "AnimatedObject.h"


void AnimatedObject::setFramesFront(sf::Image arr[], int length)
{
	for (int i = 0; i < length; ++i)
		framesFront.push_back(arr[i]);
}

void AnimatedObject::setFramesBack(sf::Image arr[], int length)
{
	for (int i = 0; i < length; ++i)
		framesBack.push_back(arr[i]);
}

void AnimatedObject::setFramesLeft(sf::Image arr[], int length)
{
	for (int i = 0; i < length; ++i)
		framesLeft.push_back(arr[i]);
}

void AnimatedObject::setFramesRight(sf::Image arr[], int length)
{
	for (int i = 0; i < length; ++i)
		framesRight.push_back(arr[i]);
}



void AnimatedObject::setIntervalFPS(int fps)
{
	intervalFPS = fps;
}

int AnimatedObject::getIntervalFPS()
{
	return intervalFPS;
}

void AnimatedObject::setIsStop(bool isStop)
{
	this->isStop = isStop;
}

bool AnimatedObject::getIsStop()
{
	return isStop;
}
