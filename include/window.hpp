/* COPYRIGHT (C) HARRY CLARK 2024 */

/* MINIMAL FRONTEND APPLICATION USING SDL AND IMGUI */

/* THIS FILE PERTAINS TOWARDS THE FUNCTIONALITY ENCOMPASSING THE */
/* INITIALISATION AND OF THE APPLICATION WINDOW */

/* NESTED INCLUDES */

#include "common.h"

/* SYSTEM INCLUDES */

#include <cstring>
#include <stdexcept>

#ifndef USE_SDL
#define USE_SDL
#include <SDL.h>
#endif


class WINDOW
{
public:
	WINDOW(const char* TITLE, int WIDTH, int HEIGHT, int B_WIDTH, int B_HEIGHT);

	static bool CREATE_WINDOW(const char* TITLE, int WIDTH, int HEIGHT);

	static SDL_Window* WINDOW_BASE;
	static SDL_Renderer* RENDERER;
	static SDL_Texture* TEXTURE_BUFFER;

	static float GET_DPI_WINDOW_SCALE();
	static void SET_FULLSCREEN(bool ENABLED) { SDL_SetWindowFullscreen(GET_WINDOW(), ENABLED ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0); }

	static SDL_Window* GET_WINDOW() { return WINDOW_BASE; }
	static SDL_Renderer* GET_RENDERER() { return RENDERER; }
	static SDL_Texture* GET_TEXTURE_BUFFER() { return TEXTURE_BUFFER; }
};
