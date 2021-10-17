#include "Engine.h"
#include <chrono>
#include <iostream>

Engine::Engine(std::string windowTitle, int windowWidth, int windowHeight)
{
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
	this->windowTitle = windowTitle;
	this->videoStyle = -1;
}

auto Engine::getCurrentTime()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

Engine::Engine(std::string windowTitle, int windowWidth, int windowHeight, int videoStyle)
{
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
	this->windowTitle = windowTitle;
	this->videoStyle = videoStyle;
}

Engine::Engine(std::string windowTitle, int videoMod)
{
	this->windowHeight = 0;
	this->windowWidth = 0;
	this->windowTitle = windowTitle;
	this->videoStyle = -1;
}

Engine::~Engine()
{
	delete render;
}

void Engine::setFps(int fps)
{
	this->fps = fps;
}

void Engine::run()
{
	this->render = new RenderWindow(VideoMode(windowWidth, windowHeight), windowTitle);
	
	sf::CircleShape shape(100.f);
	sf::RectangleShape square(sf::Vector2f(windowWidth, windowHeight));

	shape.setFillColor(sf::Color::Green);

	int fpsInterval = (int)1000 / fps;
	auto lastFrame = getCurrentTime();

	while (render->isOpen())
	{
		sf::Event event;
		while (render->pollEvent(event))
		{
			if (event.type == Event::Closed)
				render->close();
		}

		auto currentTime = getCurrentTime();

		if ((currentTime - lastFrame) < fpsInterval)
			continue;

		lastFrame = currentTime;

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			shape.move(0.0f, -1.0f);
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			shape.move(-1.0f, 0.0f);
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			shape.move(0.0f, 1.0f);
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			shape.move(1.0f, 0.0f);
		}

		render->clear();
		render->draw(square);
		render->draw(shape);
		render->display();
	}

}
