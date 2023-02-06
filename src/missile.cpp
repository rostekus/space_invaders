#include "missile.hpp"
#include "config.hpp"

Missile::Missile(bool alignment)
    : power(1), friendly(alignment)
{
    representation = MISSILE_REP;
}

Missile::Missile(bool alignment, int xPosition, int yPosition)
    : Drawable(xPosition, yPosition), power(1), friendly(alignment)
{
    representation = MISSILE_REP;
}

Missile::~Missile() {}

int Missile::getPower()
{
    return power;
}

bool Missile::getFriendly()
{
    return friendly;
}

void Missile::update()
{
    setPos(getPosX(), getPosY() - 1);
}
