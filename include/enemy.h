#ifndef ENEMY_H
#define ENEMY_H
#include "enemy.h"
#include "missile.h"
#include <iostream>

class Enemy
{
private:
    int speedX;
    int speedY;

public:
    Enemy();
    ~Enemy();
    void move(int x, int y);
    Missile shoot();
};

#endif //ENEMY_H
