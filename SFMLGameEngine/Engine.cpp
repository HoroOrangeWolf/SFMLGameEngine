#include "Engine.h"
#include <chrono>
#include <iostream>
#include "PrimitiveAreaFast.h"
#include "PrimitiveArea.h"
#include "PrimitiveEllipse.h"
#include "PrimitiveObject.h"
#include "PrimitiveTriangle.h"
#include "PrimitiveRectangle.h"
#include "Player.h"


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
	PrimitiveRectangle primitive(sf::Vector2f(5.f,5.f), sf::Vector2f(200.f, 400.f));
	//primitive.rotate(55.f);
	//PrimitiveArea primitiveArea(sf::Vector2f(0.f, 0.f), 25.f);
	PrimitiveTriangle primit(sf::Vector2f(250.f, 250.f), sf::Vector2f(50.f, 150.f));
	Player player(sf::Vector2f(150.f, 150.f));

	player.addKeyAndStore(KeyAndVector(sf::Vector2f(0.f, -1.f), sf::Keyboard::W));
	player.addKeyAndStore(KeyAndVector(sf::Vector2f(-1.f, 0.f), sf::Keyboard::A));
	player.addKeyAndStore(KeyAndVector(sf::Vector2f(0.f, 1.f), sf::Keyboard::S));
	player.addKeyAndStore(KeyAndVector(sf::Vector2f(1.f, 0.f), sf::Keyboard::D));

	player.setColor(sf::Color::Blue);
	player.setPosition(sf::Vector2f(5.f, 5.f));

	primit.rotate(48.f);
	
	primit.setColor(sf::Color::Red);
	primitive.setColor(sf::Color::Red);
	
	//PrimitiveEllipse pr(100.f, 50.f);
	//pr.setPosition(sf::Vector2f(150.f, 150.f));
	PrimitiveEllipse por(150.f, 50.f);
	PrimitiveObject obj(std::vector<sf::Vector2f>({ sf::Vector2f(0.f,0.f), sf::Vector2f(250.f, 0.f),sf::Vector2f(230.f, 230.f), sf::Vector2f(125.f, 125.f) ,sf::Vector2f(0.f, 250.f)}));

	obj.setPosition(sf::Vector2f(250.f, 250.f));
	obj.rotate(48.f);

	

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

		player.update();
		
		render->clear();
		render->draw(background);

		//test
		//obj.getToDraw(render);
		//primit.getToDraw(render);
		//primitive.getToDraw(render);
		player.getToDraw(render);

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
