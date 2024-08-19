#ifndef _GAME_
#define _GAME_

#include "Board.h"
#include "Pieces.h"
#include "IO.h"
#include <time.h>

#define WAIT_TIME 700  // Time in milliseconds


class Game
{
    public:
        Game(Board *pBoard,Pieces *pPieces,IO *pIO,int pScreenHeight);
        void drawScene();
        void createNewPiece();

        int mPosX,mPosY;
        int mPiece,mRotation;

    private:
        int mScreenHeight;
        int mNextPosX,mNextPosY;
        int mNextPiece,mNextRotation;

        Board *mBoard;
        Pieces *mPieces;
        IO *mIO;

        int getRand(int a, int b);
        void initGame();
        void DrawPiece(int px,int py,int pPiece,int pRotation);
        void DrawBoard();
};

#endif