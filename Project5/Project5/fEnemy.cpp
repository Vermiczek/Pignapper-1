#include "fEnemy.h"

fEnemy::fEnemy(int x, int y, int v)
{
	xPosition = x;
	yPosition = y;
	xVel = v;
}

fEnemy::~fEnemy()
{
}

void fEnemy::moveEnemy(int x, int y)
{
	xPosition = xPosition + x;
	yPosition = yPosition + y;
}

void accel(double xV, double yV)
{

}