#ifndef SHIP_H
#define SHIP_H
#include "ship.h"
#include "missile.h"
#include <iostream>

class Ship
{
private:
    int posX;
    int posY;
    char imgChar;

public:
    Ship(char imgChar, int x, int y);
    ~Ship();
    void move(int x, int y);
    void draw();
    Missile shoot();
};

#endif //SHIP_H
