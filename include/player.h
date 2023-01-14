#ifndef PLAYER_H
#define PLAYER_H
#include "player.h"
#include "missile.h"
#include <iostream>

class Player
{
private:
    int speed;
    char imgChar;

public:
    Missile shoot();
    void move(int x, int y);
};

#endif //PLAYER_H
