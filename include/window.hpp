/* COPYRIGHT (C) HARRY CLARK 2024 */

/* MINIMAL FRONTEND APPLICATION USING SDL AND IMGUI */

/* THIS FILE PERTAINS TOWARDS THE FUNCTIONALITY ENCOMPASSING THE */
/* INITIALISATION AND OF THE APPLICATION WINDOW */

/* NESTED INCLUDES */

#include "common.h"

/* SYSTEM INCLUDES */

#include <stdexcept>

#ifndef USE_SDL
#define USE_SDL
#include <SDL.h>
#endif

namespace FRONTEND
{
	class WINDOW
	{
		public:
			static SDL_Window* WINDOW_BASE;
			static SDL_Renderer* RENDERER;
			static SDL_Texture* TEXTURE_BUFFER;

			WINDOW(const char*, int, int, int, int);

		private:
			static float GET_DPI_WINDOW_SCALE();
			static void SET_FULLSCREEN(bool ENABLED) { SDL_SetWindowFullscreen(GET_WINDOW(), ENABLED ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0); }

			static SDL_Window* GET_WINDOW() { return WINDOW_BASE; }
	};
}
