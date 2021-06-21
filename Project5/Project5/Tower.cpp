#include "Tower.h"

Tower::Tower(int x, int y)
{
	xPosition = x;
	yPosition = y;

}

Tower::~Tower()
{
}

void Tower::setPosition(int x, int y)
{
	xPosition = x;
	yPosition = y;
}