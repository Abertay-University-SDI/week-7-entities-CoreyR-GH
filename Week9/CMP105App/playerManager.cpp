#include "playerManager.h"
#include <iostream>

playerManager::playerManager()
{
	speed = 150;
	bulletSpeed = 600;
	bulletTexture.loadFromFile("gfx/Goomba.png");
	setFillColor(sf::Color::Blue);
	setPosition(50, 300);
	setSize(sf::Vector2f(50, 50));
}

playerManager::~playerManager()
{
}

void playerManager::handleInput(Input* in)
{
	if (in->isKeyDown(sf::Keyboard::W))
	{
		velocity.y = -speed;
	}

	else if (in->isKeyDown(sf::Keyboard::S))
	{
		velocity.y = speed;
	}

	else { velocity.y = 0; }

	if (in->isKeyDown(sf::Keyboard::A))
	{
		velocity.x = -speed;
	}

	else if (in->isKeyDown(sf::Keyboard::D))
	{
		velocity.x = speed;
	}

	else { velocity.x = 0; }

	if (in->isPressed(sf::Keyboard::Space)) { spawn(); }
}

void playerManager::spawn()
{
	sf::Sprite newSprite;
	newSprite.setPosition(sf::Vector2f(getPosition().x + getSize().x/4, getPosition().y + getSize().y / 4));
	newSprite.setScale(0.1f, 0.1f);
	newSprite.setTexture(bulletTexture);
	bullets.push_back(newSprite);

}

void playerManager::update(float dt)
{
	for (int i = 0; i < bullets.size(); i++) 
	{
		bullets[i].move(bulletSpeed * dt, 0);
	}

	move(velocity * dt);
	deathCheck();
}

void playerManager::deathCheck()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].getPosition().x > 1200) { bullets.erase(bullets.begin() + i); }
	}
}

void playerManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		
		window->draw(bullets[i]);
	}
	window->draw(*this);
}
