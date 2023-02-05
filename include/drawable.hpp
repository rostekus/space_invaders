#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include <curses.h>

class Entity
{
protected:
    float *position;
    int color = COLOR_WHITE;
    int velocity;
    char representation;
    bool destroyed;

public:
    Entity();
    Entity(float x, float y);
    virtual ~Entity();
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
    virtual void detectCollision(Entity &object);
};
#endif
