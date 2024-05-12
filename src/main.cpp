/* COPYRIGHT (C) HARRY CLARK 2024 */

/* MINIMAL FRONTEND APPLICATION USING SDL AND IMGUI */

/* THIS FILE PERTAINS TOWARDS THE MAIN FUNCTIONALITY OF THE PROGRAM */

#include "window.hpp"
#include "frontend.hpp"

static bool FRONTEND_QUIT = false;
static SDL_Event EVENT_HANDLER;

int main(int argc, char** argv) 
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) 
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    if (!FRONTEND::FRONTEND_BASE::INIT(argc, argv)) 
    {
        SDL_Log("Failed to initialize frontend.");
        SDL_Quit();
        return 1;
    }

    while (!FRONTEND_QUIT)
    {
        while (SDL_PollEvent(&EVENT_HANDLER)) 
        {
            if (EVENT_HANDLER.type == SDL_QUIT) 
            {
                FRONTEND_QUIT = true;
            }
        }

        FRONTEND::FRONTEND_BASE::UPDATE();
        SDL_RenderPresent(WINDOW::RENDERER);
    }

    FRONTEND::FRONTEND_BASE::DE_INIT();
    SDL_Quit();

    return 0;
}
