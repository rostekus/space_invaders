#ifndef SPACE_INVADERS_GAMEBOARD_H
#define SPACE_INVADERS_GAMEBOARD_H
#include "drawable.h"

class GameBoard
{
private:
    int width = 50;
    int height = 10;
    Drawable board;

public:
    void draw();
    Drawable getBoard();
};

#endif //SPACE_INVADERS_GAMEBOARD_H
