#include "Enemy.h"

Enemy::Enemy(int x, int y, int v)
{
	xPosition = x;
	yPosition = y;
	xVel = v;
}

Enemy::~Enemy()
{
}

void Enemy::moveEnemy(int x, int y)
{
	xPosition = xPosition+x;
	yPosition = yPosition+y;
}