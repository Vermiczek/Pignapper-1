#pragma once
#include "Texture.h"

class Bow : public Texture
{
public:
	int xPosition = 0;
	int yPosition = 0;
	int angle = 0;
	bool shooting;
	Bow(int x, int y);
	~Bow();
	std::string imagePath = "bow.png";

	void setPosition(int x, int y);
	void setAngle(int a);
	void Rotate(int rotat);



};

