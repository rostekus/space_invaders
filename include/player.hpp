#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>

#include "drawable.hpp"
#include "missile.hpp"

class Player : public Entity
{
private:
    int lives;

public:
    Player();
    Player(int x, int y);
    ~Player();
    int getLives();
    void loseLife();
    void resetLives();
    void update() override;
    void moveLeft();
    void moveRight();
    Projectile shoot();
    void detectCollision(Entity &object) override;
};

#endif
