#pragma once

#include "Global.h"
#include "Texture.h"
#include "Player.h"
#include "Tower.h"
#include "Bow.h"
#include "Arrow.h"
#include "Enemy.h"
#include "fEnemy.h"

class Game
{
public:
	//The window we'll be rendering to
	SDL_Window * window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;
	
	//PNG image surface
	SDL_Surface* backgroundSurface = NULL;
	TTF_Font *font = NULL;
	Texture TextTexture;
	//Scene texture
	Texture backgroundTexture;
	Texture playerTexture;
	Texture towerTexture;
	Texture bowTexture;
	Texture aimTexture;
	Texture arrowTexture;
	Texture enemyTexture;
	Texture gameoverTexture;
	Texture fenemyTexture;
	//Renderer
	SDL_Renderer* renderer;
	std::vector<Arrow> arrows;
	std::vector<Enemy> enemies;
	std::vector<fEnemy> fenemies;
	Game(); // constructor
	~Game(); // destructor

			 // Method
	
	bool init();
	bool loadMedia();
	bool loadMedia(std::string path);
	bool createWindow();
	void processInput();

	void updateWindow(Player & p, Tower & t, Bow & b, int & mx, int & my);
	void closeGame();
};


