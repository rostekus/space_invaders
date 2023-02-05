#include <algorithm>
#include <curses.h>

#include "enemy.hpp"
#include "config.hpp"

#define DEF_VALUE 100
#define EF_HEALTH 100

Alien::Alien()
{
    value = DEF_VALUE;
    health = EF_HEALTH;
    representation = ALIEN_REP;
    color = COLOR_GREEN;
    moveState = 1;
    moveStateDownToggle = -1;
}

Alien::Alien(int xPosition, int yPosition)
    : Entity(xPosition, yPosition)
{
    value = DEF_VALUE;
    health = EF_HEALTH;
    representation = ALIEN_REP;
    color = COLOR_GREEN;
    velocity = 1;
    moveState = 1;
    moveStateDownToggle = -1;
}

Alien::Alien(int xPosition, int yPosition, int velocity)
    : Entity(xPosition, yPosition)
{
    value = DEF_VALUE;
    health = EF_HEALTH;
    representation = ALIEN_REP;
    color = COLOR_GREEN;
    velocity = velocity;
    moveState = 1;
    moveStateDownToggle = -1;
}

Alien::~Alien() {}

int Alien::getValue()
{
    return value;
}

int Alien::getHealth()
{
    return health;
}

int Alien::takeDamage(int damage)
{
    health = std::max(health - damage, 0);
    return health;
}

void Alien::update()
{
    if (health <= 33)
    {
        color = COLOR_RED;
    }
    else if (health <= 66)
    {
        color = COLOR_MAGENTA;
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
        // move left
        setPos(position[0] - (0.05 + 0.02 * velocity), position[1]);
        break;
    case 2:
        // move right
        setPos(position[0] + (0.05 + 0.02 * velocity), position[1]);
        break;
    case 3:
        // move down
        setPos(position[0], position[1] + 0.05 + 0.02 * velocity);
        break;
    }
}

void Alien::detectCollision(Entity &object)
{
    if (object.getRepresentation() == PROJECTILE_REP)
    {
        if (takeDamage(34) == 0)
        {
            destroy();
        }
        object.destroy();
    }
}
