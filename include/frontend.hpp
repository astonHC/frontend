/* COPYRIGHT (C) HARRY CLARK 2024 */

/* MINIMAL FRONTEND APPLICATION USING SDL AND IMGUI */

/* THIS FILE PERTAINS TOWARDS THE FUNCTIONALITY ENCOMPASSING THE */
/* INITIALISATION AND OF THE FRONTEND */

/* NESTED INCLUDES */

#include "common.h"

/* SYSTEM INCLUDES */

#include <algorithm>
#include <functional>
#include <string.h>

#ifndef USE_SDL
#define USE_SDL
#include <SDL.h>
#endif

#if defined(USE_FRONTEND)
#define USE_FRONTEND
#else 
#define USE_FRONTEND

#define			FRONTEND_DEFAULT_TITLE				"Harry Clark - MD68000"
#define			FRONTEND_FRAME_BUFFER_WIDTH			320
#define			FRONTEND_FRAME_BUFFER_HEIGHT		240
#define			FRONTEND_DEFAULT_WIDTH				320 * 2
#define			FRONTEND_DEFAULT_HEIGHT				240 * 2

namespace FRONTEND
{
	class FRONTEND_BASE
	{
	public:
		static bool INIT(int argc, char** argv);

		static void UPDATE(void);
		static void DE_INIT(void);
	};
}

#endif
