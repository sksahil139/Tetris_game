#include "include/Game.h"
#include <SDL2/SDL.h>  // SDL2 include for macOS

int main()
{
    // ----- Vars -----

    // Class for drawing stuff, it uses SDL for the rendering.
    IO mIO;
    int mScreenHeight = mIO.GetScreenHeight();

    // Pieces
    Pieces mPieces;

    // Board
    Board mBoard(&mPieces, mScreenHeight);

    // Game
    Game mGame(&mBoard, &mPieces, &mIO, mScreenHeight);

    // Get the actual clock milliseconds (SDL)
    unsigned long mTime1 = SDL_GetTicks();

    // ----- Main Loop -----
    while (!mIO.IsKeyDown(SDLK_ESCAPE))
    {
        // ----- Draw -----
        mIO.ClearScreen();         // Clear screen
        mGame.drawScene();         // Draw stuff
        mIO.UpdateScreen();        // Put the graphic context on the screen

        // ----- Input -----
        int mKey = mIO.Pollkey();

        switch (mKey)
        {
            case (SDLK_RIGHT):
            {
                if (mBoard.isPossibleMovement(mGame.mPosX + 1, mGame.mPosY, mGame.mPiece, mGame.mRotation))
                    mGame.mPosX++;
                break;
            }

            case (SDLK_LEFT):
            {
                if (mBoard.isPossibleMovement(mGame.mPosX - 1, mGame.mPosY, mGame.mPiece, mGame.mRotation))
                    mGame.mPosX--;
                break;
            }

            case (SDLK_DOWN):
            {
                if (mBoard.isPossibleMovement(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation))
                    mGame.mPosY++;
                break;
            }

            case (SDLK_x):
            {
                // Check collision from top to bottom
                while (mBoard.isPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation)) { mGame.mPosY++; }

                mBoard.storePiece(mGame.mPosX, mGame.mPosY - 1, mGame.mPiece, mGame.mRotation);

                mBoard.deletePossibleLines();

                if (mBoard.IsGameOver())
                {
                    mIO.Getkey();
                    exit(0);
                }

                mGame.createNewPiece();

                break;
            }

            case (SDLK_z):
            {
                if (mBoard.isPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, (mGame.mRotation + 1) % 4))
                    mGame.mRotation = (mGame.mRotation + 1) % 4;

                break;
            }
        }

        // ----- Vertical movement -----
        unsigned long mTime2 = SDL_GetTicks();

        if ((mTime2 - mTime1) > WAIT_TIME)
        {
            if (mBoard.isPossibleMovement(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation))
            {
                mGame.mPosY++;
            }
            else
            {
                mBoard.storePiece(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation);

                mBoard.deletePossibleLines();

                if (mBoard.IsGameOver())
                {
                    mIO.Getkey();
                    exit(0);
                }

                mGame.createNewPiece();
            }

            mTime1 = SDL_GetTicks();
        }
    }

    return 0;
}
