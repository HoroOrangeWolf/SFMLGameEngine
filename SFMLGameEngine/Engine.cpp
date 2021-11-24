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

/**
 * .
 * \brief Konstruktor okna gry
 * \param windowTitle Tytul okna
 * \param windowWidth Szerokosc okna
 * \param windowHeight Wysokosc okna
 */
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

/**
 * .
 * \brief Konstruktor okna gry
 * \param windowTitle Tytul okna
 * \param windowWidth Szerokosc okna
 * \param windowHeight Wysokosc okna
 * \param videoStyle Sposob wyswietlania okna gry
 */
Engine::Engine(std::string windowTitle, int windowWidth, int windowHeight, int videoStyle)
{
	this->windowHeight = windowHeight;
	this->windowWidth = windowWidth;
	this->windowTitle = windowTitle;
	this->videoStyle = videoStyle;
	this->color = Color::White;
}

/**
 * .
 * \brief Konstruktor okna gry
 * \param windowTitle Tytul okna
 * \param videoMode Definiuje rozmiar okna
 */
Engine::Engine(std::string windowTitle, int videoMode)
{
	this->windowHeight = 0;
	this->windowWidth = 0;
	this->windowTitle = windowTitle;
	this->videoStyle = videoStyle;
	this->color = Color::White;
}

/**
 * .
 * \brief Konstruktor okna gry
 * \param videoMode Definiuje rozmiar okna
 * \param windowTitle Tytul okna
 * \param videoStyle Sposob wyswietlania okna gry
 */
Engine::Engine(VideoMode videoMode, std::string windowTitle, int videoStyle)
{
	this->windowHeight = 0;
	this->windowWidth = 0;
	this->windowTitle = windowTitle;
	this->videoStyle = videoStyle;
	this->color = Color::White;
}

/**
 * .
 * \brief Destruktor
 */
Engine::~Engine()
{
}

/**
 * .
 * \brief Dodaj gracza do silnika
 * \param player Dodawany gracz
 */
void Engine::addPlayer(Player* player)
{
	playerList.push_back(player);
}

/**
 * .
 * \brief Usun gracza z silnika
 */
void Engine::clearPlayers()
{
	playerList.clear();
}

/**
 * .
 * \brief Dodawanie obiektu na mape
 * \param drawable Dodawany obiekt
 */
void Engine::addDrawable(DrawableObject* drawable)
{
	drawableList.push_back(drawable);
}

/**
 * .
 * \brief Usuwanie obiektu z mapy
 */
void Engine::clearDrawable()
{
	drawableList.clear();
}

/**
 * .
 * \brief Ustawianie ilosci klatek na sekunde
 * \param fps Wartosc klatek na sekunde
 */
void Engine::setFps(int fps)
{
	this->fps = fps;
}

/**
 * .
 * \brief Ustawianie koloru tla mapy
 * \param cl Kolor tla
 */
void Engine::setBackgroundColor(Color cl)
{
	this->color = cl;
}

/**
 * .
 * \brief Glowna petla silnika
 */
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

/**
 * .
 * \brief Sprawdza czy myszka jest w obrebie okna
 * \return 
 */
bool Engine::isMouseInsideWindow()
{
	Vector2i windowPoss = render->getPosition();
	Vector2u size = render->getSize();


	Vector2i mousePoss = Mouse::getPosition();


	return (windowPoss.x <= mousePoss.x && (windowPoss.x + size.x) >= mousePoss.x && windowPoss.y <= mousePoss.y && (windowPoss.y + size.y) >= mousePoss.y);
	
}

/**
 * .
 * \brief Zwroc rzeczywista pozycje myszy
 * \return 
 */
Vector2i& Engine::getTrueMousePosition()
{
	Vector2i possWindow = render->getPosition();
	Vector2i mousePoss = Mouse::getPosition();

	Vector2i buff = Vector2i(mousePoss.x - possWindow.x, mousePoss.y - possWindow.y);
	return buff;
}
