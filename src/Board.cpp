#include "include/Board.h"

Board::Board(Pieces *piece, int screenHeight)
{
    mScreenHeight = screenHeight;
    mPieces = piece;
    InitBoard();
}

int Board::getXPosInPixels(int pos)
{
    return ((BOARD_POSITION-(BLOCK_SIZE*(BOARD_WIDTH/2)))+(pos*BLOCK_SIZE));
}

int Board::getYPosInPixels(int pos)
{
    return ((mScreenHeight-(BLOCK_SIZE*BOARD_HEIGHT))+(pos*BLOCK_SIZE));
}

bool Board::isFreeBlock(int px, int py)
{
if (mBoard [px][py] == POS_FREE) return true; else return false;
}

bool Board::isPossibleMovement(int px, int py, int piece, int rotation)
{
    for (int i1 = px, i2 = 0; i1 < px + PIECE_BLOCKS; i1++, i2++)
	{
		for (int j1 = py, j2 = 0; j1 < py + PIECE_BLOCKS; j1++, j2++)
		{	
			if (	i1 < 0 			|| 
				i1 > BOARD_WIDTH  - 1	||
				j1 > BOARD_HEIGHT - 1)
			{
				if (mPieces->getBlockType (piece, rotation, j2, i2) != 0)
					return 0;		
			}

			if (j1 >= 0)	
			{
				if ((mPieces->getBlockType (piece, rotation, j2, i2) != 0) &&
					(!isFreeBlock (i1, j1))	)
					return false;
			}
		}
	}

	// No collision
	return true;
}

void Board::storePiece(int px, int py, int piece, int rotation)
{
    for(int i1=px,i2=0;i1<px+PIECE_BLOCKS;i1++,i2++){
        for(int j1=py,j2=0;j1<py+PIECE_BLOCKS;j1++,j2++){
            if(mPieces->getBlockType(piece,rotation,j2,i2)!=0){
                mBoard[i1][j1]=POS_FILLED;
            }
        }
    }
}

void Board::deletePossibleLines()
{
    for(int j=0;j<BOARD_HEIGHT;j++){
        int i=0;
        while (i<BOARD_WIDTH)
        {
            if(mBoard[i][j]!=POS_FILLED)break;
            i++;
        }
        if(i==BOARD_WIDTH)DeleteLine(j);
    }
}

bool Board::IsGameOver()
{
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        if(mBoard[i][0]==POS_FILLED)return true;    
    }
    return false;
}

void Board::InitBoard()
{
    for(int i=0;i<BOARD_WIDTH;i++){
        for (int j = 0; j <BOARD_HEIGHT; j++){
            mBoard[i][j]=POS_FREE;
        }
    }
    
}

void Board::DeleteLine(int py)
{
    for(int j=py;j>0;j--){
        for(int i=0;i<BOARD_WIDTH;i++){
            mBoard[i][j]=mBoard[i][j-1];
        }
    }
}
