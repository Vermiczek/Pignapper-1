#include "Game.h"
SDL_Event ev;

int framesE = 0;
int framesFE = 0;
int end = 0;
int randY;

Game::Game()
{
}


Game::~Game()
{
}


bool Game::init()
{
	srand(time(NULL));
	//Initialization flag
	bool success = true;
	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		success = false;
	}

	//Initialize SDL_ttf
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		window = SDL_CreateWindow(
			"Swiniostrzal",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (renderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load background texture
	if (!backgroundTexture.loadFromFile("background.png", renderer))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	// load player texture
	if (!playerTexture.loadFromFile("player.png", renderer))
	{
		printf("Failed to load player texture image!\n");
		success = false;
	}

	// load player texture
	if (!arrowTexture.loadFromFile("arrow.png", renderer))
	{
		printf("Failed to load player texture image!\n");
		success = false;
	}

	// load tower texture
	if (!towerTexture.loadFromFile("tower.png", renderer))
	{
		printf("Failed to load tower texture image!\n");
		success = false;
	}

	// load tower texture
	if (!bowTexture.loadFromFile("bow.png", renderer))
	{
		printf("Failed to load tower texture image!\n");
		success = false;
	}

	if (!aimTexture.loadFromFile("aim.png", renderer))
	{
		printf("Failed to load tower texture image!\n");
		success = false;
	}

	if (!enemyTexture.loadFromFile("enemy.png", renderer))
	{
		printf("Failed to load tower texture image!\n");
		success = false;
	}


	if (!gameoverTexture.loadFromFile("gameover.png", renderer))
	{
		printf("Failed to load tower texture image!\n");
		success = false;
	}


	if (!fenemyTexture.loadFromFile("fenemy.png", renderer))
	{
		printf("Failed to load tower texture image!\n");
		success = false;
	}

	

		//Loading success flag
		

		//Open the font
		font = TTF_OpenFont("aller.ttf", 28);
		if (font == NULL)
		{
			printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
			success = false;
		}
		
		
		return success;
	}





bool Game::loadMedia(std::string path)
{
	//Loading success flag
	bool success = true;

	//Load background texture
	if (!backgroundTexture.loadFromFile("background.png", renderer))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	return success;
}


bool Game::createWindow()
{
	bool success = true;
	//Create window
	window = SDL_CreateWindow("SDL Tutorial",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}


void Game::updateWindow(Player &p, Tower &t, Bow &b, int &mx, int &my)
{
	//Get window surface
	screenSurface = SDL_GetWindowSurface(window);

	SDL_GetMouseState(&mx, &my);
	b.angle = (atan2((b.yPosition + 20 - my), (b.xPosition + 20 - mx)) * 180 / M_PI);
	//Clear screen
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);

	//Render background texture to screen
	backgroundTexture.render(0, 0, renderer);


	//Render Foo' to the screen
	playerTexture.render(p.xPosition, p.yPosition, renderer);


	towerTexture.render(t.xPosition, t.yPosition, renderer);
	bowTexture.renderFlip(b.xPosition, b.yPosition, NULL, b.angle, NULL, SDL_FLIP_NONE, renderer);
	int rnd;
	int rnd1;
	framesE = framesE + 1;
	framesFE = framesFE + 1;
	rnd = rand() % 3+1;
	if ((framesE - 240) == 0)
	{
		Enemy enemy(1000, 495, rnd);
		enemies.push_back(enemy);
		framesE = 0;
	}
	for (auto it = enemies.begin(); it != enemies.end(); it++)
	{

		enemyTexture.renderFlip(it->xPosition, it->yPosition, NULL, it->angle, NULL, SDL_FLIP_NONE, renderer);
		it->moveEnemy(-it->xVel, 0);
		
		if (it->xPosition <= -10&&it->xPosition <= -10)
		{
			if(it->hit==0)
			p.health = p.health-1;
			it->hit = 1;
}
	}
	
	rnd = rand() % 4+1;
	if ((framesFE - 100) == 0)
	{
		
		randY = rand() %300+20;
		fEnemy fenemy(1000, randY, rnd);
		fenemies.push_back(fenemy);
		framesFE = 0;
	}
	for (auto it = fenemies.begin(); it != fenemies.end(); it++)
	{

		fenemyTexture.renderFlip(it->xPosition, it->yPosition, NULL, it->angle, NULL, SDL_FLIP_NONE, renderer);
		it->moveEnemy(-it->xVel, it->yVel);

		if (it->xPosition <= -10 && it->xPosition <= -10)
		{
			if (it->hit == 0)
			{
				p.health = p.health - 1;
				p.arrows = p.arrows + 5;
			}
			it->hit = 1;
		}
	}
	

	for (auto it = arrows.begin(); it != arrows.end(); it++)
	{
		for (auto itr = fenemies.begin(); itr != fenemies.end(); itr++)
		{
			if (it->xPosition+40 >= itr->xPosition && it->yPosition+10 >= itr->yPosition && it->yPosition + 10 <= itr->yPosition + 40 && it->xPosition + 40 <= itr->xPosition+40&& itr->hit==0)
			{
				std::cout << "hit";
				itr->hit = 1;
				it->hit = 1;
				p.arrows = p.arrows + 1;
				rnd1 = rand() % 10;
				if (rnd1 == 6)
				{
					p.arrows = p.arrows + 1;
				}
				p.score = p.score + 30;
			}
		}
	}

	for (auto it = arrows.begin(); it != arrows.end(); it++)
	{
		for (auto itr = enemies.begin(); itr != enemies.end(); itr++)
		{
			if (it->xPosition + 40 >= itr->xPosition && it->yPosition + 10 >= itr->yPosition && it->yPosition + 10 <= itr->yPosition + 40 && it->xPosition + 40 <= itr->xPosition + 40 && itr->hit == 0)
			{
				std::cout << "hit";
				itr->hit = 1;
				it->hit = 1;
				p.arrows = p.arrows + 1;
				rnd1 = rand() % 10;
				if (rnd1 == 6)
				{
					p.arrows = p.arrows + 1;
				}
				p.score = p.score + 30;
			}
		}
	}
	for (auto it = arrows.begin(); it != arrows.end(); it++)
	{
		arrowTexture.renderFlip(it->xPosition, it->yPosition, NULL, it->angle, NULL, SDL_FLIP_NONE, renderer);
		it->accel(0, 0.07);
		it->moveArrow();
		it->didHit();
		it->hitStop();
		if (it->hit == 0)
		{
			it->Rotate();
		}
	}
	
	int x = fenemies.size();
	for (int i = 0; i < x; i++)
	{

		if (fenemies[i].hit)
		{
			if (x > 1)
			{
				std::swap(fenemies[i], fenemies[x-1]);
			}
			fenemies.pop_back();
				x = fenemies.size();
				
		}
	}

	int y = arrows.size();
	for (int i = 0; i < y; i++)
	{

		if (arrows[i].hit)
		{
			if (y > 1)
			{
				std::swap(arrows[i], arrows[y - 1]);
			}
			arrows.pop_back();
			y = arrows.size();
			p.arrows = p.arrows - 1;
			p.score = p.score - 10;
			break;
		}
	}

	int z = enemies.size();
	for (int i = 0; i < z; i++)
	{

		if (enemies[i].hit)
		{
			if (z > 1)
			{
				std::swap(enemies[i], enemies[z - 1]);
			}
			enemies.pop_back();
			z = enemies.size();

		}
	}

	
	
	aimTexture.render(mx - 20, my - 20, renderer);
	std::string hptxt;
	std::stringstream ss;
	ss << p.health;
	hptxt = ss.str();

	
		//Render text
		SDL_Color textColor = { 255, 0, 0 };
		if (!TextTexture.loadFromRenderedText(hptxt, textColor, renderer, font))
		{
			printf("Failed to render text texture!\n");
		}
		TextTexture.render(100, 565, renderer);


		if (!TextTexture.loadFromRenderedText("HP:", textColor, renderer, font))
		{
			printf("Failed to render text texture!\n");
		}
		TextTexture.render(55, 565, renderer);

		std::string artxt;
		std::stringstream dd;
		dd << p.arrows;
		artxt = dd.str();




		//Render text
		SDL_Color textColor1 = { 0,0,0};
		if (!TextTexture.loadFromRenderedText(artxt, textColor1, renderer, font))
		{
			printf("Failed to render text texture!\n");
		}
		TextTexture.render(300, 565, renderer);

		if (!TextTexture.loadFromRenderedText("Arrows:", textColor1, renderer, font))
		{
			printf("Failed to render text texture!\n");
		}
		TextTexture.render(200, 565, renderer);


		std::string sctxt;
		std::stringstream ff;
		ff << p.score;
		sctxt = ff.str();

		//Render text
		SDL_Color textColor2 = { 255,255,255};
		if (!TextTexture.loadFromRenderedText(sctxt, textColor2, renderer, font))
		{
			printf("Failed to render text texture!\n");
		}
		TextTexture.render(600, 565, renderer);
		if (!TextTexture.loadFromRenderedText("Score:", textColor2, renderer, font))
		{
			printf("Failed to render text texture!\n");
		}
		TextTexture.render(520, 565, renderer);

		if (p.health <= 0)
		{
			end++;
			if (end>0)
				gameoverTexture.render(0, 0, renderer);
		}
	//Update screen
	SDL_RenderPresent(renderer);
	std::cout << p.score << std::endl;
}

void Game::closeGame()
{
	//Free loaded images
	playerTexture.free();
	backgroundTexture.free();
	towerTexture.free();

	//Destroy window	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;


	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

}
