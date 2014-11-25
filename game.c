#include <SDL.h>
#include <SDL_image.h>
#include "game.h"
#include "settings.h"

/**
* Check if square is not taken. Set symbol for current player and calculate for winner.
* @param x The x board coordinate
* @param y The y board coordinate
*/
int do_process_turn(int x, int y) {

	int correctionX;
	int correctionY;
	char result_info[1024];
	correctionX = ((MWWIDTH / 3) - IMG_WIDTH) / 2 - IMG_LINE_WIDTH;
	correctionY = ((MWHEIGHT / 3) - IMG_HEIGHT) / 2 - IMG_LINE_WIDTH;

	if (GameBoard[x][y] == 0) { // square not taken
		TurnCounter++;
		GameBoard[x][y] = player_current.value;

		render_texture(player_current.texture, (MWWIDTH / 3) * (x)+correctionX, (MWHEIGHT / 3) * (y)+correctionY);
		if (check_winner(player_current.value, x, y))
		{
			SDL_snprintf(result_info, sizeof result_info, "%s%s", player_current.player_name, " Win!");
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Tic Tac Toe result", result_info, window);
			restart_game();
		}
		if (TurnCounter > 8)
			restart_game();
		switch_players();

		return 1;
	}
	return 0;
}

/**
*Switch players between turns.
*/
void switch_players()
{
	if (player_current.value == player_O.value)
		player_current = player_X;
	else
		player_current = player_O;
}

/**
* Set 0 to all positions in board.
*/
void resest_boar()
{
	TurnCounter = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
		GameBoard[i][j] = 0;
		}
}

/**
* Check if current player is winner.
* This function compare horizontal, vertical and diagonal positions.
* @param current_player_value The current player value stored on board
* @param x The x coordinate
* @param y The y coordinate
*/
int check_winner(int current_player_value, int x, int y) {

	// check vertical
	for (int i = 0; i < 3; i++) {
		if (GameBoard[x][i] != current_player_value) {
			break; // not winning move
		}
		if (i == 2) {
			return 1; // winning move
		}
	}

	// check horizontal
	for (int i = 0; i < 3; i++) {
		if (GameBoard[i][y] != current_player_value) {
			break;
		}
		if (i == 2) {
			return 1;
		}
	}

	// check diagonal
	/*	1 0 0
	0 1 0
	0 0 1	*/
	if (x == y) {
		for (int i = 0; i < 3; i++) {
			if (GameBoard[i][i] != current_player_value) {
				break;
			}
			if (i == 2) {
				return 1;
			}
		}
	}

	// check diagonal
	/*	0 0 1
	0 1 0
	1 0 0	*/
	for (int i = 0; i < 3; i++) {
		if (GameBoard[i][2 - i] != current_player_value) {
			break;
		}
		if (i == 2) {
			return 1;
		}
	}
	return 0;
}

/**
* Close game and start again.
*/
void restart_game()
{
	shut_down();
	initialize();
}

/**
* <summary>
* Initialize main window. Load textures for players. Setup default player.
* </summary>
*/
void initialize()
{
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	window = SDL_CreateWindow(MWTITLE,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, MWHEIGHT,
		MWHEIGHT, 0);

	renderer = SDL_CreateRenderer(window, -1, 0);
	background_image = IMG_Load(MWBACKGROUND);
	backgroundTexture = SDL_CreateTextureFromSurface(renderer, background_image);

	player_O.image = IMG_Load(OIMAGE);
	player_O.texture = SDL_CreateTextureFromSurface(renderer, player_O.image);
	player_O.value = PLAYER_O_VALUE;
	player_O.player_name = PLAYER_O_NAME;

	player_X.image = IMG_Load(XIMAGE);
	player_X.texture = SDL_CreateTextureFromSurface(renderer, player_X.image);
	player_X.value = PLAYER_X_VALUE;
	player_X.player_name = PLAYER_X_NAME;

	player_current = player_O;

	SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

/**
*Close current game.
*/
int shut_down()
{
	SDL_DestroyTexture(backgroundTexture);
	SDL_FreeSurface(background_image);
	SDL_DestroyTexture(player_O.texture);
	SDL_FreeSurface(player_O.image);
	SDL_DestroyTexture(player_X.texture);
	SDL_FreeSurface(player_X.image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
	resest_boar();
	return 0;
}

/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
* the texture's width and height and show this texture on the screen.
* @param texture The source texture we want to draw
* @param x The x coordinate to draw to
* @param y The y coordinate to draw to
*/
void render_texture(SDL_Texture *texture, int x, int y){
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	//Query the texture to get its width and height to use
	SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(renderer, texture, NULL, &dst);
	SDL_RenderPresent(renderer);
}