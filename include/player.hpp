#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>

#include "drawable.hpp"
#include "missile.hpp"

class Player : public Drawable
{
private:
    int lives;

public:
    Player();
    Player(int x, int y);
    ~Player();
    int getLives();
    int getposX();
    int getposY();
    void loseLife();
    void resetLives();
    void update() override;
    void moveLeft();
    void moveRight();
    Missile shoot();
    void detectCollision(Drawable &object) override;
};

#endif
