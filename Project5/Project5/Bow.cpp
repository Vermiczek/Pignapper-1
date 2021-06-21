#include "Bow.h"

Bow::Bow(int x, int y)
{
	xPosition = x;
	yPosition = y;

}

Bow::~Bow()
{

}

void Bow::setPosition(int x, int y)
{
	xPosition = x;
	yPosition = y;
}

void Bow::setAngle(int a)
{
	angle = a;
}

void Bow::Rotate(int rotat)
{
	angle = angle + rotat;
}