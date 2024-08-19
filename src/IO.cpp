#include "include/IO.h"

SDL_Renderer* IO::mRenderer = nullptr;
SDL_Window* IO::mWindow = nullptr;
Uint32 IO::mColors[COLOR_MAX] = {
    0x000000FF, 0xFF0000FF, 0x00FF00FF, 0x0000FFFF, 
    0x00FFFFFF, 0xFF00FFFF, 0xFFFF00FF, 0xFFFFFFFF
};

IO::IO()
{
    InitGraph();
}

void IO::DrawRectangle(int pX1, int pY1, int pX2, int pY2, color pC)
{
    SDL_SetRenderDrawColor(mRenderer, (mColors[pC] >> 24) & 0xFF, 
                                     (mColors[pC] >> 16) & 0xFF, 
                                     (mColors[pC] >> 8) & 0xFF, 
                                     mColors[pC] & 0xFF);
    SDL_Rect rect = { pX1, pY1, pX2 - pX1, pY2 - pY1 };
    SDL_RenderFillRect(mRenderer, &rect);
}

void IO::ClearScreen()
{
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mRenderer);
}

int IO::GetScreenHeight()
{
    int h;
    SDL_GetWindowSize(mWindow, nullptr, &h);
    return h;
}

int IO::InitGraph()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return -1;
    }

    mWindow = SDL_CreateWindow("SDL2 Example", 
                               SDL_WINDOWPOS_CENTERED, 
                               SDL_WINDOWPOS_CENTERED, 
                               640, 480, SDL_WINDOW_SHOWN);
    if (!mWindow) {
        SDL_Quit();
        return -1;
    }

    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
    if (!mRenderer) {
        SDL_DestroyWindow(mWindow);
        SDL_Quit();
        return -1;
    }

    return 0;
}

int IO::Pollkey()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_KEYDOWN)
            return event.key.keysym.sym;
        else if (event.type == SDL_QUIT)
            exit(3);
    }
    return -1;
}

int IO::Getkey()
{
    SDL_Event event;
    while (true)
    {
        SDL_WaitEvent(&event);
        if (event.type == SDL_KEYDOWN)
            break;
        if (event.type == SDL_QUIT)
            exit(3);
    }
    return event.key.keysym.sym;
}

int IO::IsKeyDown(int pKey)
{
    const Uint8* mKeytable;
    int mNumkeys;
    SDL_PumpEvents();
    mKeytable = SDL_GetKeyboardState(&mNumkeys);
    return mKeytable[pKey];
}

void IO::UpdateScreen()
{
    SDL_RenderPresent(mRenderer);
}
