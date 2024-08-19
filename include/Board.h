#ifndef _BOARD_
#define _BOARD_

#define BOARD_LINE_WIDTH 6
#define BLOCK_SIZE 16
#define BOARD_POSITION 320
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20	
#define MIN_VERTICAL_MARGIN 20
#define MIN_HORIZONTAL_MARGIN 20
#define PIECE_BLOCKS 5	

#include "Pieces.h"

class Board
{
public:
    Board(Pieces *piece,int screenHeight);
    int getXPosInPixels(int pos);
    int getYPosInPixels(int pos);
    bool isFreeBlock(int px,int py);
    bool isPossibleMovement(int px,int py,int peice,int rotation);
    void storePiece(int px,int py,int piece,int rotation);
    void deletePossibleLines();
    bool IsGameOver();

private:
    enum{POS_FREE,POS_FILLED};
    int mBoard [BOARD_WIDTH][BOARD_HEIGHT]; // Board that contains the pieces
    Pieces *mPieces;
    int mScreenHeight;

    void InitBoard();
    void DeleteLine (int pY);
};

#endif