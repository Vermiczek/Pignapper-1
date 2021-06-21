#pragma once
#include "Texture.h"

class Tower : public Texture
{

public:
	void setPosition(int x, int y);
	int xPosition = 50;
	int yPosition = 400;
	Tower(int x, int y);
	~Tower();
	std::string imagePath = "tower.png";


};


