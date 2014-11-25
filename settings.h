/** Main window height */
#ifndef MWHEIGHT
#define MWHEIGHT 600
#endif /* MWHEIGHT */

/** Main window width */
#ifndef MWWIDTH
#define MWWIDTH 600
#endif /* MWWIDTH */

/** Img height */
#ifndef IMG_HEIGHT
#define IMG_HEIGHT 145
#endif /* IMG_HEIGHT */

/** Img width */
#ifndef IMG_WIDTH
#define IMG_WIDTH 145
#endif /* IMG_WIDTH */

/** Background image line width */
#ifndef IMG_LINE_WIDTH
#define IMG_LINE_WIDTH 6
#endif /* IMG_LINE_WIDTH */


/** Main window caption */
#ifndef MWTITLE
#define MWTITLE "Tic Tac Toe - SDL2"
#endif /* MWTITLE */

/** Main window background image */
#ifndef MWBACKGROUND
#define MWBACKGROUND "img/background.gif"
#endif /* MWBACKGROUND */

/** O image */
#ifndef OIMAGE
#define OIMAGE "img/o.png"
#endif /* OIMAGE */

/** X image */
#ifndef XIMAGE
#define XIMAGE "img/x.png"
#endif /* XIMAGE */

/** Player names and values */
#ifndef PLAYER_NAMES_AND_VALUES
#define PLAYER_NAMES_AND_VALUES
#define PLAYER_O_NAME "Player O"
#define PLAYER_X_NAME "Player X"
#define PLAYER_O_VALUE 1
#define PLAYER_X_VALUE 2
#endif /* PLAYER_NAMES_AND_VALUES */


/** SDL global handlers */
#ifndef SDL_GLOBAL_HANDLERS
SDL_Window * window;
SDL_Event event;
SDL_Renderer * renderer;
SDL_Surface * background_image;
SDL_Texture * backgroundTexture;
#endif /* SDL_GLOBAL_HANDLERS */
