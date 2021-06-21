#include "Player.h"

Player::Player(int x, int y)
{
	xPosition = x;
	yPosition = y;

}

Player::~Player()
{
}

void Player::setPosition(int x, int y)
{
	xPosition = x;
	yPosition = y;
}