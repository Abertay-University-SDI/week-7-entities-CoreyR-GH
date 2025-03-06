#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isPressed(sf::Keyboard::I)) 
	{
		ballManager.spawn();
	}

	if (input->isPressed(sf::Keyboard::L))
	{
		spriteManager.spawn();
	}
}

// Update game objects
void Level::update(float dt)
{
	ballManager.update(dt);
	spriteManager.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	ballManager.render(window);
	spriteManager.render(window);

	endDraw();
}
