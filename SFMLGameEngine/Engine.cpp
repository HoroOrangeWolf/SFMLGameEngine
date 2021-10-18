#include "Engine.h"
#include <chrono>
#include <iostream>
#include "PrimitiveRectangle.h"
#include "PrimitiveArea.h"
#include "PrimitiveTriangle.h"

Engine::Engine(std::string windowTitle, int windowWidth, int windowHeight)
{
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
	this->windowTitle = windowTitle;
	this->videoStyle = -1;
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

Engine::Engine(std::string windowTitle, int videoMod)
{
	this->windowHeight = 0;
	this->windowWidth = 0;
	this->windowTitle = windowTitle;
	this->videoStyle = -1;
	this->color = Color::White;
}

Engine::~Engine()
{
	delete render;
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
	this->render = new RenderWindow(VideoMode(windowWidth, windowHeight), windowTitle);
	
	sf::RectangleShape background(sf::Vector2f(windowWidth, windowHeight));
	PrimitiveRectangle primitive(sf::Vector2f(50.f,50.f), sf::Vector2f(200.f, 20.f));
	PrimitiveArea primitiveArea(sf::Vector2f(0.f, 0.f), 25.f);
	PrimitiveTriangle primit(sf::Vector2f(40.f, 50.f), sf::Vector2f(50.f, 150.f));


	background.setFillColor(this->color);

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



		Vector2i currentPosition = Mouse::getPosition();

		if (currentPosition.x != lastposs.x && currentPosition.y != lastposs.y && isMouseInsideWindow()) {
			//std::cout << "-----------------------------------------------------------------------------------" << std::endl;
			//std::cout << "Mouse possition: x " << currentPosition.x << " y " << currentPosition.y << std::endl;

			Vector2i mouseTruePosition = getTrueMousePosition();

			//std::cout << "Mouse possition: x " << mouseTruePosition.x << " y " << mouseTruePosition.y << std::endl;

			lastposs = currentPosition;
		}
		
		render->clear();
		render->draw(background);

		{
			std::list<MoveableBlock>::iterator beg = this->constantBlocks.begin();

			while (beg != this->constantBlocks.end())
			{
				MoveableBlock& a = *beg;

				render->draw(a);
				beg++;
			}

			
		}

		{
			std::list<MoveableBlock>::iterator beg = this->toMoveList.begin();

			while (beg != this->toMoveList.end())
			{
				MoveableBlock &a = *beg;

			

				a.moveByStoredVector();

				render->draw(a);
				beg++;
			}
		}

		//test

		render->draw(primit.getToDraw());
		render->draw(primitive.getToDraw());

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

void Engine::addConstantBlock(MoveableBlock& constant)
{
	this->constantBlocks.push_back(constant);
}




void Engine::addMoveableBlock(MoveableBlock& move)
{
	this->toMoveList.push_back(move);
}
