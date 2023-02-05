#include "drawable.hpp"
#include <math.h>

#define DEF_X_POS 1.0f;
#define DEF_Y_POS 1.0f;

Drawable::Drawable()
{
    position = new float[2];
    position[0] = DEF_X_POS;
    position[1] = DEF_Y_POS;
}

Drawable::Drawable(float xPosition, float yPosition)
{
    position = new float[2];
    position[0] = xPosition;
    position[1] = yPosition;
}

Drawable::~Drawable()
{
    delete[] position;
}

float *Drawable::getPos()
{
    return position;
}

int Drawable::getColor()
{
    return color;
}

int Drawable::getVel()
{
    return velocity;
}

void Drawable::setPos(float x, float y)
{
    position[0] = x;
    position[1] = y;
}

int Drawable::getPosX()
{
    return (int)floor(position[0]);
}

int Drawable::getPosY()
{
    return (int)floor(position[1]);
}

void Drawable::destroy()
{
    destroyed = true;
}

bool Drawable::isDestroyed()
{
    return destroyed;
}

char Drawable::getRepresentation()
{
    return representation;
}

void Drawable::detectCollision(Drawable &object) {}