#include "Engine.h"
#include <chrono>
#include <iostream>
#include "PrimitiveAreaFast.h"
#include "PrimitiveArea.h"
#include "PrimitiveEllipse.h"
#include "PrimitiveObject.h"
#include "PrimitiveTriangle.h"
#include "PrimitiveRectangle.h"
#include "BitmapHandler.h"
#include "Player.h"


Engine::Engine(std::string windowTitle, int windowWidth, int windowHeight)
{
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
	this->windowTitle = windowTitle;
	this->videoStyle = videoStyle;
	this->color = Color::White;
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
	this->color = Color::White;
}

Engine::Engine(std::string windowTitle, int videoMode)
{
	this->windowHeight = 0;
	this->windowWidth = 0;
	this->windowTitle = windowTitle;
	this->videoStyle = videoStyle;
	this->color = Color::White;
}

Engine::Engine(VideoMode videoMode, std::string windowTitle, int videoStyle)
{
	this->windowHeight = 0;
	this->windowWidth = 0;
	this->windowTitle = windowTitle;
	this->videoStyle = videoStyle;
	this->color = Color::White;
}

Engine::~Engine()
{
}

void Engine::addPlayer(Player* player)
{
	playerList.push_back(player);
}

void Engine::clearPlayers()
{
	playerList.clear();
}

void Engine::addDrawable(DrawableObject* drawable)
{
	drawableList.push_back(drawable);
}

void Engine::clearDrawable()
{
	drawableList.clear();
}

void Engine::setFps(int fps)
{
	this->fps = fps;
}

void Engine::setBackgroundColor(Color cl)
{
	this->color = cl;
}

void Engine::run()
{
	this->render = new RenderWindow(VideoMode(windowWidth, windowHeight), windowTitle, videoStyle);

	sf::RectangleShape background(sf::Vector2f(windowWidth, windowHeight));

	background.setFillColor(this->color);

	int fpsInterval = (int)1000 / fps;
	auto lastFrame = getCurrentTime();

	Vector2i lastposs = Mouse::getPosition();

	while (render->isOpen())
	{
		sf::Event events;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
			render->close();
			delete render;
			return;
		}

		while (render->pollEvent(events))
		{
			if (events.type == Event::Closed) {
				render->close();
				delete render;
				return;
			}
		}

		auto currentTime = getCurrentTime();

		if ((currentTime - lastFrame) < fpsInterval)
			continue;

		lastFrame = currentTime;



		Vector2i currentPosition = Mouse::getPosition();

		if (currentPosition.x != lastposs.x && currentPosition.y != lastposs.y && isMouseInsideWindow()) {
			//std::cout << "-----------------------------------------------------------------------------------" << std::endl;
			//std::cout << "Mouse possition: x " << currentPosition.x << " y " << currentPosition.y << std::endl;

			Vector2i mouseTruePosition = getTrueMousePosition();

			lastposs = currentPosition;
		}

		render->clear();

		for (int i = 0; i < drawableList.size(); ++i) {
			DrawableObject* drawable = drawableList[i];

			drawable->getToDraw(render);
		}


		for (int i = 0; i < playerList.size(); ++i) {
			Player* player = playerList[i];

			player->update();
			player->animate();
			player->getToDraw(render);

		}
	
		render->display();

	}

	delete render;

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
