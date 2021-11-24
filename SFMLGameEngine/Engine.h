#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "DrawableObject.h"

using namespace sf;

class Engine {

private:
	int windowWidth, windowHeight, videoMode, videoStyle = sf::Style::Default;
	int fps = 60;
	VideoMode mode;
	std::string windowTitle;
	RenderWindow *render;
	sf::Color color;
	std::vector<Player*> playerList;
	std::vector<DrawableObject*> drawableList;
	auto getCurrentTime();


public:
	Engine(std::string windowTitle, int windowWidth, int windowHeight, int videoStyle);
	Engine(std::string windowTitle, int videoMod);
	Engine(VideoMode videoMode, std::string windowTitle, int videoStyle);
	Engine(std::string windowTitle, int windowWidth, int windowHeight);
	~Engine();
	void addPlayer(Player* player);
	void clearPlayers();
	void addDrawable(DrawableObject* drawable);
	void clearDrawable();
	void setFps(int fps);
	void setBackgroundColor(sf::Color);
	void run();
	bool isMouseInsideWindow();
	Vector2i &getTrueMousePosition();
};