#ifndef SPACE_INVADERS_GAMEBOARD_H
#define SPACE_INVADERS_GAMEBOARD_H
#include "drawable.h"

class GameBoard
{
private:
    int width;
    int height;
    Drawable board;

public:
    void draw();
    Drawable getBoard();
};

#endif //SPACE_INVADERS_GAMEBOARD_H
