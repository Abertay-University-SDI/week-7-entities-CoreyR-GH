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
}

// Update game objects
void Level::update(float dt)
{
	ballManager.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	ballManager.render(window);

	endDraw();
}
