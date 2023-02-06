#ifndef Drawable_hpp
#define Drawable_hpp

#include <stdio.h>
#include <curses.h>

class Drawable
{
protected:
    float *position;
    int color = COLOR_WHITE;
    int velocity;
    char representation;
    bool destroyed;

public:
    Drawable();
    Drawable(float x, float y);
    virtual ~Drawable();
    float *getPos();
    int getColor();
    int getVel();
    void setPos(float x, float y);
    int getPosX();
    int getPosY();
    void destroy();
    bool isDestroyed();
    char getRepresentation();
    virtual void update() = 0;
    virtual void detectCollision(Drawable &object);
};
#endif
