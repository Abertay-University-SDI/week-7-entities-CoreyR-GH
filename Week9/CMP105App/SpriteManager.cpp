#include "SpriteManager.h"

#include <iostream>

SpriteManager::SpriteManager()
{
	texture.loadFromFile("gfx/Goomba.png");
	counter = 0;
	speed = 300;

	if (!font.loadFromFile("font/arial.ttf")) { std::cout << "error, text not loaded"; }
	text.setFont(font);
	text.setPosition(sf::Vector2f(50, 625));

	for (int i = 0; i < 40; i++)
	{
		spriteList[i] = sf::Sprite();
		spriteList[i].setTexture(texture);
		aliveList[i] = false;
		spriteList[i].setScale(0.25f, 0.25f);
	}
	text.setString("Current sprites active 0");
}

SpriteManager::~SpriteManager()
{
}

void SpriteManager::spawn()
{
	static bool spawnCheck;
	spawnCheck = false;

	for (int i = 0; i < 40; i++)
	{
		if (!aliveList[i] && !spawnCheck)
		{
			counter++;
			spawnCheck = true;
			aliveList[i] = true;
			spriteList[i].setPosition(sf::Vector2f(rand() % 1200, -50));
			text.setString("Current sprites active " + std::to_string(counter));
			return;
		}
	}
}

void SpriteManager::update(float dt)
{
	for (int i = 0; i < 40; i++) 
	{
		if (aliveList[i]) { spriteList[i].move(sf::Vector2f(0, speed * dt)); }
	}
	deathCheck();
}

void SpriteManager::deathCheck()
{
	for (int i = 0; i < 40; i++)
	{
		if (aliveList[i] && spriteList[i].getPosition().y > 676)
		{
			counter--;
			aliveList[i] = false;
			text.setString("Current sprites active " + std::to_string(counter));
		}
	}
}

void SpriteManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < 40; i++)
	{
		if (aliveList[i]){ window->draw(spriteList[i]); }
	}

	window->draw(text);
}
