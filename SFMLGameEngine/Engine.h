#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Moveable.h"

using namespace sf;

class Engine {

private:
	int windowWidth, windowHeight, videoStyle;
	int fps = 60;
	VideoMode mode;
	std::string windowTitle;
	RenderWindow *render;
	std::list<Drawable&> toDrawList;
	
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
	void addDrawable(Drawable& draw);


};