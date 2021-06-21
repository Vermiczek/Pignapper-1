#pragma once
#include "Texture.h"

class Enemy : public Texture
{

public:
	void setPosition(int x, int y);
	int xPosition = 0;
	int yPosition = 0;
	int angle = 0;
	int xVel;
	bool hit = 0;
    Enemy(int x, int y, int v);
	~Enemy();
	void moveEnemy(int x, int y);
	void accel(double xV, double yV);
	std::string imagePath = "enemy.png";
	



};

