#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>

#include "drawable.hpp"

class Enemy : public Drawable
{
private:
    int health;
    int moveState;
    int moveStateDownToggle;

public:
    Enemy();
    Enemy(int x, int y);
    Enemy(int x, int y, int v);
    ~Enemy();
    int getHealth();
    int takeDamage(int damage);
    void update() override;
    void detectCollision(Drawable &object) override;
};
#endif
