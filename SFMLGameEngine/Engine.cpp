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
	
	sf::RectangleShape shape(sf::Vector2f(150, 150));
	sf::RectangleShape square(sf::Vector2f(windowWidth, windowHeight));

	sf::RectangleShape secondSquare(sf::Vector2f(150.f, 150.f));

	shape.setFillColor(sf::Color::Green);
	secondSquare.setFillColor(Color::Red);

	secondSquare.move(150.0f, 150.0f);

	int fpsInterval = (int)1000 / fps;
	auto lastFrame = getCurrentTime();

	Vector2i lastposs = Mouse::getPosition();

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

		if (Keyboard::isKeyPressed(Keyboard::X))
		{
			shape.setRotation(shape.getRotation() + 1.0f);
		}

		



		

		Vector2i currentPosition = Mouse::getPosition();

		if (currentPosition.x != lastposs.x && currentPosition.y != lastposs.y && isMouseInsideWindow()) {
			std::cout << "-----------------------------------------------------------------------------------" << std::endl;
			std::cout << "Mouse possition: x " << currentPosition.x << " y " << currentPosition.y << std::endl;

			Vector2i mouseTruePosition = getTrueMousePosition();

			std::cout << "Mouse possition: x " << mouseTruePosition.x << " y " << mouseTruePosition.y << std::endl;

			lastposs = currentPosition;
		}
		

		std::cout << secondSquare.getGlobalBounds().intersects(shape.getGlobalBounds()) << std::endl;



		render->clear();
		render->draw(square);
		render->draw(shape);
		render->draw(secondSquare);
		render->display();
	}

}

bool Engine::isMouseInsideWindow()
{
	Vector2i windowPoss = render->getPosition();
	Vector2u size = render->getSize();


	Vector2i mousePoss = Mouse::getPosition();



	return (windowPoss.x <= mousePoss.x && (windowPoss.x + size.x) >= mousePoss.x && windowPoss.y <= mousePoss.y && (windowPoss.y + size.y) >= mousePoss.y);
	
}

Vector2i& Engine::getTrueMousePosition()
{
	Vector2i possWindow = render->getPosition();
	Vector2i mousePoss = Mouse::getPosition();

	Vector2i buff = Vector2i(mousePoss.x - possWindow.x, mousePoss.y - possWindow.y);
	return buff;
}
