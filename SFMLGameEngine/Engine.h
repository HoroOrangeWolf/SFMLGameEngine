#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Engine {

private:
	int windowWidth, windowHeight, videoStyle;
	int fps = 60;
	VideoMode mode;
	std::string windowTitle;
	RenderWindow *render;
	auto getCurrentTime();

public:
	Engine(std::string windowTitle, int windowWidth, int windowHeight, int videoStyle);
	Engine(std::string windowTitle, int videoMod);
	Engine(std::string windowTitle, int windowWidth, int windowHeight);
	~Engine();
	void setFps(int fps);
	void run();
	bool isMouseInsideWindow();
	Vector2i &getTrueMousePosition();


};