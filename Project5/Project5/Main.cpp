//Using SDL and standard IO
#include "Game.h"
bool shot = 0;
int frames = 0;
int my, mx;
SDL_Event e;
double myv, mxv;
int main(int argc, char* args[])
{
	// Create game manager 
	Game gm;

	//create player
	Player player1(70, 290);
	Tower tower1(50, 325);
	Bow bow1(70, 290);
	

	

	// initialize and create window
	if (!gm.init())
	{
		printf("Unable to initialize!\n");
	}
	else
	{
		// load media
		if (!gm.loadMedia())
		{
			printf("Unable to load media!\n");
		}
		else {
			// running flag
			bool running = true;

			//Create event handler
			SDL_Event e;

			

			//Main game loop
			while (running)
			{
				frames++;

				// handle events
				while (SDL_PollEvent(&e) != 0)
				{

					//user quits
					if (e.type == SDL_QUIT)
					{
						gm.closeGame();
					}




					if (player1.arrows > 0) {
						if (e.type = SDL_MOUSEBUTTONDOWN) {
							if (e.button.button == SDL_BUTTON_LEFT)
							{


								if (frames >= 30)
								{

									double b = 0;
									SDL_GetMouseState(&mx, &my);
									double lenght;
									lenght = 10;

									b = atan2(90 - mx, 310 - my);


									mxv = -(lenght * sin(b));
									myv = -(lenght * cos(b));
									if (mx == 0)
									{
										myv = 5;
									}

									if (my == 0)
									{
										mxv = 5;
									}
									Arrow arrow1(70, 300, mxv, myv);
									gm.arrows.push_back(arrow1);
									shot = 1;
									frames = 0;
								}

							}
						}
					}
				}
				shot = 0;



				//Update the window
				
			/*	arrow1.accel(0, 0.05);
				arrow1.moveArrow();
				arrow1.didHit();
				arrow1.hitStop();
				if (arrow1.hit == 0)
				{
					arrow1.Rotate();
				}*/
				gm.updateWindow(player1,tower1,bow1,my,mx);
				

			} // Game loop end
		}
	}


	// QUIT SDL
	system("pause");
	gm.closeGame();
	return 0;
}