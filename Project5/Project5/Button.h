#include "Global.h"

class Button
{
public:
	//Initializes internal variables
	Button();

	//Sets top left position
	void setPosition(int x, int y);

	//Handles mouse event
	void handleEvent(SDL_Event* e);

	//Shows button sprite
	void render();

private:
	
	SDL_Point mPosition;

	
};
#pragma once
