#ifndef MISSILE_H
#define MISSILE_H
#include "missile.h"
#include <iostream>

class Missile
{
private:
    char imgChar;
    int posX;
    int posY;
    int speed;

public:
    void missile(int x, int y, int speed);
    void updatePos(int x, int y);
    char draw();
};

#endif //MISSILE_H
