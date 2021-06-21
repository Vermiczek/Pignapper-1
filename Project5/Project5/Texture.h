#pragma once

#include "Global.h"
class Texture
{

public:
	//Initializes variables
	Texture();

	//Deallocates memory
	~Texture();

	//Loads image at specified path
	SDL_Texture* loadFromFile(std::string path, SDL_Renderer* renderer);

	//Deallocates texture
	void free();
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor, SDL_Renderer* renderer, TTF_Font* font);
	
	//Renders texture at given point
	void render(int x, int y, SDL_Renderer* renderer);

	void renderFlip(int x, int y, SDL_Rect * clip, double angle, SDL_Point * center, SDL_RendererFlip flip, SDL_Renderer* renderer);

	//Gets image dimensions
	int getWidth();
	int getHeight();
	
protected:
	//The actual hardware texture
	SDL_Texture * texture;

	//Image dimensions
	int width;
	int height;
};


