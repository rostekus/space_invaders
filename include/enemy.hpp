#ifndef Alien_hpp
#define Alien_hpp

#include <stdio.h>

#include "drawable.hpp"

class Alien : public Drawable
{
private:
    int value;
    int health;
    int moveState;
    int moveStateDownToggle;

public:
    Alien();
    Alien(int x, int y);
    Alien(int x, int y, int v);
    ~Alien();
    int getValue();
    int getHealth();
    int takeDamage(int damage);
    void update() override;
    void detectCollision(Drawable &object) override;
};
#endif
