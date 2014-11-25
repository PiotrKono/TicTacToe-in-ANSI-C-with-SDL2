#include <SDL.h>
#include "settings.h"
#include "game.h"

int quit = 0;

/**
* TicTacToe demo application.
* <summary>
* Main funciton for game.
* </summary>
*/
int main(int argc, char ** argv)
{
	int mouse_x;
	int mouse_y;

	initialize();

	while (!quit)
	{
		SDL_WaitEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			quit = 1;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (SDL_GetMouseState(&mouse_x, &mouse_y) &SDL_BUTTON_LMASK) {
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						if ((mouse_x < (MWWIDTH / 3) * (i + 1)) && (mouse_y < (MWHEIGHT / 3) * (j + 1))) {
							do_process_turn(i, j);							
							i = 3; //breake i
							break;
						}
					}
				}
			}
			break;
		}
	}
	return shut_down();
}

