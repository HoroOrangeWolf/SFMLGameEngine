#pragma once
#include <SFML/Graphics.hpp>
#include "Moveable.h"
using namespace sf;

class Engine {

private:
	int windowWidth, windowHeight, videoStyle;
	int fps = 60;
	VideoMode mode;
	std::string windowTitle;
	RenderWindow *render;
	sf::Color color;
	std::list<MoveableBlock> toMoveList;
	std::list<MoveableBlock> constantBlocks;
	auto getCurrentTime();


public:
	Engine(std::string windowTitle, int windowWidth, int windowHeight, int videoStyle);
	Engine(std::string windowTitle, int videoMod);
	Engine(std::string windowTitle, int windowWidth, int windowHeight);
	~Engine();
	void setFps(int fps);
	void setBackgroundColor(sf::Color);
	void run();
	bool isMouseInsideWindow();
	Vector2i &getTrueMousePosition();
	void addMoveableBlock(MoveableBlock& move);
	void addConstantBlock(MoveableBlock& constant);
};