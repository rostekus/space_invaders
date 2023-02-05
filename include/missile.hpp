#ifndef Missile_hpp
#define Missile_hpp

#include <stdio.h>
#include "drawable.hpp"

class Missile : public Drawable
{
private:
    int power;
    bool friendly;

public:
    Missile(bool alignment);
    Missile(bool alignment, int x, int y);
    ~Missile();
    int getPower();
    bool getFriendly();
    void update() override;
};

#endif
