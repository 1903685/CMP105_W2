#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput();
	void update();
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	bool MouseHold;
	int PosX;
	int PosY;

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	// Add your object here
	sf::CircleShape Circle;
	sf::Font font;
	sf::Text text;
};