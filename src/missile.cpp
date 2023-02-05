#include "missile.hpp"
#include "config.hpp"

Projectile::Projectile(bool alignment)
    : power(1), friendly(alignment)
{
    representation = PROJECTILE_REP;
}

Projectile::Projectile(bool alignment, int xPosition, int yPosition)
    : Entity(xPosition, yPosition), power(1), friendly(alignment)
{
    representation = PROJECTILE_REP;
}

Projectile::~Projectile() {}

int Projectile::getPower()
{
    return power;
}

bool Projectile::getFriendly()
{
    return friendly;
}

void Projectile::update()
{
    setPos(getPosX(), getPosY() - 1);
}
