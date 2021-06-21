#pragma once
#include "Texture.h"

class Arrow : public Texture
{
public:
	int xPosition = 0;
	int yPosition = 0;
	int angle = 0;
	bool hit = 0;
	double xVel=0;
	double yVel=0;
	Arrow(int x, int y, double xVel, double yVel);
	~Arrow();
	std::string imagePath = "bow.png";

	void setPosition(int x, int y);
	void setAngle(int a);
	void Rotate();
	void accel(double xV, double yV);
	void moveArrow();
	void hitStop();
	void didHit();



};

