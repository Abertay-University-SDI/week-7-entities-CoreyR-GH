#pragma once

#include "Framework/GameObject.h"
#include <vector>

class SpriteManager
{
private:
	sf::Sprite spriteList[40];
	bool aliveList[40];
	sf::Texture texture;
	int counter;
	float speed;
	sf::Text text;
	sf::Font font;

public:
	SpriteManager();
	~SpriteManager();

	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);
};
