#pragma once

#include "Framework/GameObject.h"
#include <vector>

class playerManager : public GameObject
{
private:
	float speed;
	float bulletSpeed;
	sf::Texture bulletTexture;
	std::vector<sf::Sprite> bullets;

public:
	playerManager();
	~playerManager();

	void handleInput(Input* in);
	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);
};

