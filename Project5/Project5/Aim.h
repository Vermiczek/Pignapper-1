#pragma once

#include "Texture.h"

class Aim : public Texture
{

public:
	int xPosition = 0;
	int yPosition = 0;
	Aim(int x, int y);
	~Aim();
	std::string imagePath = "aim.png";



};

