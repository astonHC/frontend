/* COPYRIGHT (C) HARRY CLARK 2024 */

/* MINIMAL FRONTEND APPLICATION USING SDL AND IMGUI */

/* THIS FILE PERTAINS TOWARDS THE FUNCTIONALITY ENCOMPASSING THE */
/* INITIALISATION AND OF THE APPLICATION WINDOW */

/* NESTED INCLUDES */

#include "window.hpp"

SDL_Window* WINDOW::WINDOW_BASE = nullptr;
SDL_Renderer* WINDOW::RENDERER = nullptr;
SDL_Texture* WINDOW::TEXTURE_BUFFER = nullptr;

/* CONSTRUCTOR WINDOW OBJECT - THIS WILL ACT AS A DUMMY, ALLOWING FOR THE CREATION */
/* OF OUR OWN LOCAL ARGS TO USE WITHIN THE SDL API */

WINDOW::WINDOW(const char* TITLE, int WIDTH, int HEIGHT, int B_WIDTH, int B_HEIGHT)
{

}

/* CREATE AN SDL WINDOW */

SDL_Window* WINDOW::CREATE_WINDOW(const char* TITLE, int WIDTH, int HEIGHT)
{
	WINDOW::WINDOW_BASE = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
						WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN 
													| SDL_WINDOW_ALLOW_HIGHDPI);

	if (WINDOW::WINDOW_BASE == nullptr)
	{
		throw new std::runtime_error("SDL_CreateWindow: couldn't be initialised %x");
	}

	return WINDOW::WINDOW_BASE;
}


SDL_Renderer* WINDOW::CREATE_RENDERER(SDL_Window* WINDOW)
{
	SDL_SetHint(SDL_HINT_RENDER_BATCHING, "1");

	SDL_Renderer* RENDERER = SDL_CreateRenderer(WINDOW, -1, SDL_RENDERER_TARGETTEXTURE);

	if (RENDERER == nullptr)
	{
		throw new std::runtime_error("SDL_CreateRenderer: failed with the following message");
	}

	return RENDERER;

}
