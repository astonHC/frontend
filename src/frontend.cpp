/* COPYRIGHT (C) HARRY CLARK 2024 */

/* MINIMAL FRONTEND APPLICATION USING SDL AND IMGUI */

/* THIS FILE PERTAINS TOWARDS THE FUNCTIONALITY ENCOMPASSING THE */
/* INITIALISATION AND OF THE FRONTEND */

/* NESTED INCLUDES */

using namespace FRONTEND;

#include "frontend.hpp"
#include "window.hpp"

/* INITIALISE THE MAIN WINDOW CORRESPONDENCE */
/* BY EVOKING METHODS WHICH PERTAIN TOWARDS WINDOW SIZE, PROPERTIES, ETC */

bool FRONTEND_BASE::INIT(int argc, char** argv)
{
	WINDOW* WINDOW_BASE;

	#undef USE_SDL
	SDL_SetHint("SDL_WINDOW_DPI_SCALE", "1");

	/* CREATE A NEW MEDIA LAYER SUCH THAT IT TAKES INTO ACCOUNT THE CORRESPODENCE */
	/* FROM THE WINDOW AND THE EMULATOR */

	if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER) < 0)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error: %x", "Unable to initialise SDL2", NULL);
	}

	else
	{
		WINDOW_BASE = new WINDOW(FRONTEND_DEFAULT_TITLE, FRONTEND_DEFAULT_WIDTH,
								FRONTEND_DEFAULT_HEIGHT, FRONTEND_FRAME_BUFFER_WIDTH, 
														FRONTEND_FRAME_BUFFER_HEIGHT);
	}
}