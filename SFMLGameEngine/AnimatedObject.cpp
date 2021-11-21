#include "AnimatedObject.h"

void AnimatedObject::setFrames(sf::Image arr[])
{
	int size = sizeof(arr);
	for (int i = 0; i < size; ++i)
		frames.push_back(arr[i]);

}

void AnimatedObject::addFrame(sf::Image img)
{
	frames.push_back(img);
}

void AnimatedObject::clearFrames()
{
	frames.clear();
}

void AnimatedObject::setIntervalFPS(int fps)
{
	intervalFPS = fps;
}

void AnimatedObject::setIsStop(bool isStop)
{
	this->isStop = isStop;
}

bool AnimatedObject::getIsStop()
{
	return isStop;
}
