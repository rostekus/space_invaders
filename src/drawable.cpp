#include "drawable.hpp"
#include <math.h>

#define DEF_X_POS 1.0f;
#define DEF_Y_POS 1.0f;

Entity::Entity()
{
    position = new float[2];
    position[0] = DEF_X_POS;
    position[1] = DEF_Y_POS;
}

Entity::Entity(float xPosition, float yPosition)
{
    position = new float[2];
    position[0] = xPosition;
    position[1] = yPosition;
}

Entity::~Entity()
{
    delete[] position;
}

float *Entity::getPos()
{
    return position;
}

int Entity::getColor()
{
    return color;
}

int Entity::getVel()
{
    return velocity;
}

void Entity::setPos(float x, float y)
{
    position[0] = x;
    position[1] = y;
}

int Entity::getPosX()
{
    return (int)floor(position[0]);
}

int Entity::getPosY()
{
    return (int)floor(position[1]);
}

void Entity::destroy()
{
    destroyed = true;
}

bool Entity::isDestroyed()
{
    return destroyed;
}

char Entity::getRepresentation()
{
    return representation;
}

void Entity::detectCollision(Entity &object) {}