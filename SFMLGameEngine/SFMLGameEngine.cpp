#include <SFML/Graphics.hpp>
#include <iostream>

#include "Engine.h"
#include "KeyAndVector.h"
#include "BitmapHandler.h"
#include "PrimitiveTriangle.h"
#include "PrimitiveArea.h"
#include "PrimitiveEllipse.h"
#include "PrimitiveObject.h"
#include "LineSegment.h"
#include "PrimitiveAreaFast.h"
#include <chrono>
#include <thread>


int main()
{

	//Część 1
	//Linia
	LineSegment segmentLine(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(45.f, 45.f));

	segmentLine.setColor(sf::Color::Blue);

	segmentLine.setPosition(sf::Vector2f(50.f, 50.f));

	//Kolo

	PrimitiveArea area(sf::Vector2f(100.f, 50.f), 50.f);

	area.setColor(sf::Color::Green);

	//Kolo szybkoo

	PrimitiveAreaFast areaFast(sf::Color::White, 25.f);

	areaFast.setPosition(sf::Vector2f(250.f, 50.f));

	//Elipsa

	PrimitiveEllipse elipse(100.f, 150.f);

	elipse.setColor(sf::Color::Magenta);

	elipse.setPosition(sf::Vector2f(450.f, 500.f));

	//Wielokąt

	PrimitiveObject object(std::vector<sf::Vector2f>({ sf::Vector2f(0.f,0.f), sf::Vector2f(250.f, 0.f),sf::Vector2f(230.f, 230.f), sf::Vector2f(125.f, 125.f) ,sf::Vector2f(0.f, 250.f) }));

	object.setPosition(sf::Vector2f(50.f, 250.f));
	object.setColor(sf::Color::Yellow);

	//Kwadrat

	PrimitiveRectangle rectangle(sf::Vector2f(350.f, 50.f),sf::Vector2f(50.f, 150.f));

	rectangle.setColor(sf::Color::Magenta);

	//Trójkąt

	PrimitiveTriangle triangle(sf::Vector2f(300.f, 50.f), sf::Vector2f(100.f, 300.f));

	triangle.setColor(sf::Color::Green);




	Player player(sf::Vector2f(150.f, 150.f));

	player.addKeyAndStore(KeyAndVector(sf::Vector2f(0.f, -3.f), sf::Keyboard::W));
	player.addKeyAndStore(KeyAndVector(sf::Vector2f(-3.f, 0.f), sf::Keyboard::A));
	player.addKeyAndStore(KeyAndVector(sf::Vector2f(0.f, 3.f), sf::Keyboard::S));
	player.addKeyAndStore(KeyAndVector(sf::Vector2f(3.f, 0.f), sf::Keyboard::D));

	sf::Image ims[] = { BitmapHandler::getImageFromFile("images/13.png"),
		BitmapHandler::getImageFromFile("images/14.png"),
		BitmapHandler::getImageFromFile("images/15.png"),
		BitmapHandler::getImageFromFile("images/16.png")
	};

	player.setFramesFront(ims, 4);

	sf::Image ims1[] = { BitmapHandler::getImageFromFile("images/9.png"),
		BitmapHandler::getImageFromFile("images/10.png"),
		BitmapHandler::getImageFromFile("images/11.png"),
		BitmapHandler::getImageFromFile("images/12.png")
	};

	player.setFramesBack(ims1, 4);

	sf::Image ims2[] = { BitmapHandler::getImageFromFile("images/1.png"),
		BitmapHandler::getImageFromFile("images/2.png"),
		BitmapHandler::getImageFromFile("images/3.png"),
		BitmapHandler::getImageFromFile("images/4.png")
	};

	player.setFramesRight(ims2, 4);

	sf::Image ims3[] = { BitmapHandler::getImageFromFile("images/5.png"),
		BitmapHandler::getImageFromFile("images/6.png"),
		BitmapHandler::getImageFromFile("images/7.png"),
		BitmapHandler::getImageFromFile("images/8.png")
	};

	player.setFramesLeft(ims3, 4);


	std::cout << "Rozpoczecie prezentacji\n" << std::endl;

	std::cout << "Pokaz nr 1: Obiekty w silniku\n" << std::endl;

	std::cout << "Nacisnij Q aby przejsc do dalszej prezentacji\n" << std::endl;

    Engine engine("title", 800, 800);
	engine.setBackgroundColor(sf::Color::Black);

	//Prezentacja 1
	engine.addDrawable(&segmentLine);
	engine.addDrawable(&area);
	engine.addDrawable(&areaFast);
	engine.addDrawable(&object);
	engine.addDrawable(&rectangle);
	engine.addDrawable(&triangle);
	engine.addDrawable(&elipse);

	engine.run();

	engine.clearDrawable();



	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	//Prezentacja 2

	std::cout << "Pokaz nr 2: Rotowanie\n" << std::endl;

	std::cout << "Nacisnij Q aby przejsc do dalszej prezentacji\n" << std::endl;

	engine.addDrawable(&triangle);
	engine.run();

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	
	std::cout << "Pokaz nr 3: Rotowanie\n" << std::endl;

	std::cout << "Nacisnij Q aby przejsc do dalszej prezentacji\n" << std::endl;

	triangle.rotate(25.f);
	engine.run();

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	std::cout << "Pokaz nr 4: Skalowanie\n" << std::endl;

	std::cout << "Nacisnij Q aby przejsc do dalszej prezentacji\n" << std::endl;

	triangle.rotate(-25.f);
	triangle.scale(0.25f);

	engine.run();

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	engine.clearDrawable();

	std::cout << "Pokaz nr 5: Move\n" << std::endl;

	std::cout << "Nacisnij Q aby przejsc do dalszej prezentacji\n" << std::endl;

	engine.addDrawable(&rectangle);

	engine.run();

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));


	std::cout << "Pokaz nr 6: Move\n" << std::endl;

	std::cout << "Nacisnij Q aby przejsc do dalszej prezentacji\n" << std::endl;
	engine.clearDrawable();

	rectangle.translate(sf::Vector2f(250.f, 250.f));

	engine.addDrawable(&rectangle);


	engine.run();


	std::this_thread::sleep_for(std::chrono::milliseconds(1000));


	std::cout << "Pokaz nr 7: Animacje i poruszanie\n" << std::endl;

	std::cout << "Nacisnij Q aby zakonczyc\n" << std::endl;
	engine.clearDrawable();

	rectangle.translate(sf::Vector2f(250.f, 250.f));

	engine.addPlayer(&player);

	engine.run();

    return 0;
}