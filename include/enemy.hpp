#ifndef Alien_hpp
#define Alien_hpp

#include <stdio.h>

#include "drawable.hpp"

class Enemy : public Drawable
{
private:
    int value;
    int health;
    int moveState;
    int moveStateDownToggle;

public:
    Enemy();
    Enemy(int x, int y);
    Enemy(int x, int y, int v);
    ~Enemy();
    int getValue();
    int getHealth();
    int takeDamage(int damage);
    void update() override;
    void detectCollision(Drawable &object) override;
};
#endif
