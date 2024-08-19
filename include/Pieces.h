#ifndef _PIECES_
#define _PIECES_

class Pieces{
    public:
        int getBlockType(int piece,int rotation,int px,int py);
        int getXinitialPos(int piece,int rotation);
        int getYinitialPos(int piece,int rotation);
};

#endif