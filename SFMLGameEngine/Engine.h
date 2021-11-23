#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Engine {

private:
	int windowWidth, windowHeight, videoMode, videoStyle = sf::Style::Default;
	int fps = 60;
	VideoMode mode;
	std::string windowTitle;
	RenderWindow *render;
	sf::Color color;
	auto getCurrentTime();


public:
	Engine(std::string windowTitle, int windowWidth, int windowHeight, int videoStyle);
	Engine(std::string windowTitle, int videoMod);
	Engine(VideoMode videoMode, std::string windowTitle, int videoStyle);
	Engine(std::string windowTitle, int windowWidth, int windowHeight);
	~Engine();
	void setFps(int fps);
	void setBackgroundColor(sf::Color);
	void run();
	bool isMouseInsideWindow();
	Vector2i &getTrueMousePosition();
};