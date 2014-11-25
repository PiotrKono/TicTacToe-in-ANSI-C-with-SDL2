/*Definition for player type*/
#ifndef PLAYER_TYPE
/**Definition for player type*/
typedef struct
{
	SDL_Surface * image;
	SDL_Texture * texture;
	int value;
	char * player_name;
} PLAYER_TYPE;
#endif /* PLAYER_TYPE */

/* Declare palyers */
#ifndef PLAYERS
PLAYER_TYPE player_X;
PLAYER_TYPE player_O;
PLAYER_TYPE player_current;
#endif /* PLAYERS */

/* Method definitions*/
#ifndef GAME_METHODS
int do_process_turn(int x, int y);
void switch_players();
void resest_boar();
int check_winner(int current_player_value, int x, int y);
void initialize();
int shut_down();
void restart_game();
void render_texture(SDL_Texture *texture, int x, int y);
#endif /* GAME_METHODS */


/** Global variables*/
#ifndef GAME_VARIABLES
int GameBoard[3][3];
unsigned  int TurnCounter;
#endif /* GAME_VARIABLES */
