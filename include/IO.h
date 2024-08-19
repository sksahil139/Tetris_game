#ifndef _IO_
#define _IO_

// ------ Includes -----

#ifdef _WIN32
#include "SDL/include/SDL.h"							
#include "SDL/SDL_GfxPrimitives/SDL_gfxPrimitives.h"
#pragma comment(lib, "SDL/lib/SDL.lib")
#pragma comment(lib, "SDL/SDL_GfxPrimitives/SDL_GfxPrimitives_Static.lib")
#elif defined(__linux__)
#include <SDL/SDL.h>									
#include "SDL/SDL_GfxPrimitives/sdl_gfxprimitives.h"	
#elif defined(__APPLE__)
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#endif



// ------ Enums -----

enum color {BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, COLOR_MAX}; // Colors


// --------------------------------------------------------------------------------
//									 IO
// --------------------------------------------------------------------------------

class IO
{
public:
    IO();
    void DrawRectangle(int pX1, int pY1, int pX2, int pY2, color pC);
    void ClearScreen();
    int GetScreenHeight();
    int InitGraph();
    int Pollkey();
    int Getkey();
    int IsKeyDown(int pKey);
    void UpdateScreen();

private:
    static SDL_Renderer *mRenderer;
    static SDL_Window *mWindow;
    static Uint32 mColors[COLOR_MAX];
};

#endif