#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "BeachBallManager.h"
#include "SpriteManager.h"
#include "playerManager.h"
#include <string>
#include <iostream>


class Level : public BaseLevel{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();

private:
	// Default variables for level class.
	BeachBallManager ballManager;
	SpriteManager spriteManager;
	playerManager player;
};