#pragma once

#include "Framework/GameObject.h"
#include <vector>

class SpriteManager
{
	std::vector<sf::Sprite> spriteList;

public:
	SpriteManager();
	~SpriteManager();

	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);
};

