#pragma once
#include "Texture.h"

class fEnemy : public Texture
{

public:
	void setPosition(int x, int y);
	int xPosition = 0;
	int yPosition = 0;
	int angle = 0;
	bool hit = 0;
	double xVel = 0;
	double yVel = 0;
	fEnemy(int x, int y, int v);
	~fEnemy();
	void moveEnemy(int x, int y);
	std::string imagePath = "fenemy.png";
	
	void accel(double yV);


};

