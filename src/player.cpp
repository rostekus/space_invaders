#include "player.hpp"
#include "config.hpp"

#define DEF_LIVES 2

Player::Player()
{
    lives = DEF_LIVES;
    representation = PLAYER_REP;
}

Player::Player(int x, int y)
{
    lives = DEF_LIVES;
    position[0] = x;
    position[1] = y;
    representation = PLAYER_REP;
}

Player::~Player() {}

void Player::moveRight()
{
    setPos(position[0] + 1, position[1]);
}

void Player::moveLeft()
{
    setPos(position[0] - 1, position[1]);
}

Projectile Player::shoot()
{
    return Projectile(true, getPosX(), getPosY() + 1);
}

int Player::getLives()
{
    return lives;
}

void Player::update() {}

void Player::loseLife()
{
    lives = lives - 1;
}

void Player::resetLives()
{
    lives = DEF_LIVES;
}

void Player::detectCollision(Entity &object)
{
    if (object.getRepresentation() == ALIEN_REP)
    {
        loseLife();
    }
}
