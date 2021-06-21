#pragma once
#include "Texture.h"

class Player : public Texture
{

public:
	void setPosition(int x, int y);
	int xPosition = 0;
	int yPosition = 0;
	int health=5;
	int arrows = 20;
	int score = 0;
	Player(int x, int y);
	~Player();
	std::string imagePath = "player.png";


	
};

