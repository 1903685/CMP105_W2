#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	if (!font.loadFromFile("font/arial.ttf")) {

	}
	text.setFont(font);
	text.setFillColor(sf::Color::Red);
	text.setCharacterSize(26);

	Circle.setFillColor(sf::Color::Red);
	Circle.setRadius(26);

	input->setMouseLDown(false);
}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::W)) 
	{
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "W was pressed"<< std::endl;
	}

	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L))
	{
		input->setKeyUp(sf::Keyboard::J); 
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);
		std::cout << "JKL were pressed" << std::endl;
	}
	if (input->isMouseRDown()) 
	{
		input->setMouseRDown(false);
		input->getMouseX();
		input->getMouseY();
		Circle.setPosition(input->getMouseX()-Circle.getRadius(), input->getMouseY() - Circle.getRadius());
	}

	if (input->isMouseLDown()) {
		//std::cout << "Mouse is pressed" << std::endl;
		//PosX = input->getMouseX();
		//PosY = input->getMouseY();
	}

	//Mouse actually held down, mouse tracker false
	if (input->isMouseLDown() && !MouseHold)
	{
		MouseHold = true;
		PosX=input->getMouseX();
		PosY=input->getMouseY();
	}

	//Mouse actually isn't held down, mouse tracker true
	if (!input->isMouseLDown() && MouseHold)
	{
		MouseHold = false;
		 input->getMouseX();
		 input->getMouseY();
		 int distanceX = (input->getMouseX() - PosX);
		 int distanceY = (input->getMouseY() - PosY);
		 int Thewholesqr = (pow(distanceX, 2) + pow(distanceY, 2));
		 int Thewhole = sqrt(Thewholesqr);
		 std::cout << Thewhole<< std::endl;

	}

}

// Update game objects
void Level::update()
{
	text.setString("X: " + std::to_string(PosX) + " Y: " + std::to_string(PosY) + "\n" +
					"input->isMouseLDown(): " + std::to_string(input->isMouseLDown()) + "\n" +
					"MouseHold: " + std::to_string(MouseHold)
					);

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		exit(0);
	}
	
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(text);
	window->draw(Circle);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}