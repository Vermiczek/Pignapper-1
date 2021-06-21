#include "Arrow.h"

Arrow::Arrow(int x, int y, double xV, double yV)
{
	xPosition = x;
	yPosition = y;
	xVel = xV;
	yVel = yV;
	

}

Arrow::~Arrow()
{

}



void Arrow::accel(double xV, double yV)
{
	xVel = xVel + xV;
	yVel = yVel + yV;

}

void Arrow :: didHit()
{
	if (yPosition >= 525)
	{
		hit = 1;
	}
}

void Arrow::hitStop()
{
	if (hit==1)
	{
		xVel = 0;
		yVel = 0;
	}
}

void Arrow::moveArrow()
{
	xPosition = xPosition + xVel;
	yPosition = yPosition + yVel;

}
void Arrow::setPosition(int x, int y)
{
	xPosition = x;
	yPosition = y;
}

void Arrow::setAngle(int a)
{
	angle = a;
}

void Arrow::Rotate()
{
	angle = atan2(yVel,xVel)*180/M_PI;
}