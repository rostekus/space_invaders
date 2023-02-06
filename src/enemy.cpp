#include <algorithm>
#include <curses.h>

#include "enemy.hpp"
#include "config.hpp"

#define DEF_VALUE 100
#define DEF_HEALTH 100

Enemy::Enemy()
{
    value = DEF_VALUE;
    health = DEF_HEALTH;
    representation = ENEMY_REP;
    color = COLOR_GREEN;
    moveState = 1;
    moveStateDownToggle = -1;
}

Enemy::Enemy(int xPosition, int yPosition)
    : Drawable(xPosition, yPosition)
{
    value = DEF_VALUE;
    health = DEF_HEALTH;
    representation = ENEMY_REP;
    color = COLOR_GREEN;
    velocity = 1;
    moveState = 1;
    moveStateDownToggle = -1;
}

Enemy::Enemy(int xPosition, int yPosition, int velocity)
    : Drawable(xPosition, yPosition)
{
    value = DEF_VALUE;
    health = DEF_HEALTH;
    representation = ENEMY_REP;
    color = COLOR_GREEN;
    velocity = velocity;
    moveState = 1;
    moveStateDownToggle = -1;
}

Enemy::~Enemy() {}

int Enemy::getValue()
{
    return value;
}

int Enemy::getHealth()
{
    return health;
}

int Enemy::takeDamage(int damage)
{
    health = std::max(health - damage, 0);
    return health;
}

void Enemy::update()
{
    if (health <= 33)
    {
        color = COLOR_RED;
    }
    else if (health <= 66)
    {
        color = COLOR_YELLOW;
    }

    if (getPosY() == moveStateDownToggle && getPosX() == 1)
    {
        moveState = 2;
        moveStateDownToggle = -1;
    }
    else if (getPosY() == moveStateDownToggle && getPosX() == 29)
    {
        moveState = 1;
        moveStateDownToggle = -1;
    }
    else if (getPosX() == 1)
    {
        moveState = 3;
        moveStateDownToggle = getPosY() + 1;
    }
    else if (getPosX() == 29)
    {
        moveState = 3;
        moveStateDownToggle = getPosY() + 1;
    }

    switch (moveState)
    {
    case 1:
        setPos(position[0] - (0.05 + 0.02 * velocity), position[1]);
        break;
    case 2:
        setPos(position[0] + (0.05 + 0.02 * velocity), position[1]);
        break;
    case 3:
        setPos(position[0], position[1] + 0.05 + 0.02 * velocity);
        break;
    }
}

void Enemy::detectCollision(Drawable &object)
{
    if (object.getRepresentation() == MISSILE_REP)
    {
        if (takeDamage(34) == 0)
        {
            destroy();
        }
        object.destroy();
    }
}
