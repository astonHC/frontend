/* COPYRIGHT (C) HARRY CLARK 2024 */

/* FRONTEND FOR GUI APPLICATIONS IN C */

/* THIS FILE PERTAINS TOWARDS THE MAIN FUNCTIONALITY OF THE FRONTEND */
/* ENCORPETATING TYPES AND METHODS PERTAINING TOWARDS THE GENERAL PRE-REQUISITIES */

#ifndef FRONTEND_H
#define FRONTEND_H

/* NESTED INCLUDES */

#include "common.h"
#include "md_util.h"

/* SDL INCLUDES */

#if defined(USE_SDL)
#define USE_SDL
#else
#define USE_SDL

#include <SDL.h>

#endif

#if defined(USE_FRONTEND)
#define USE_FRONTEND
#else
#define USE_FRONTEND

typedef struct FRONTEND
{
    void(*FRONTEND_FPS)(bool TV_MODE);
    void(*FRONTEND_HANDLER)(void);
    void(*FRONTEND_FREE)(void);
    bool(*FRONTEND_TURBO);

    SDL_Window* FRONTEND_WIN;
    SDL_Renderer* FRONTEND_RENDER;
    SDL_Texture* FRONTEND_TEXTURE;

} FRONTEND;

int FRONTEND_INIT(int argc, char** argv);
int FRONTEND_PAL_FPS(int VALUE) { return MD_FRAMERATE_PAL(VALUE); }
int FRONTEND_NTSC_FPS(int VALUE) { return MD_FRAMERATE_NTSC(VALUE); }

void INIT_WINDOW(SDL_Window* WINDOW, char, int, int, int, int);

#endif
#endif