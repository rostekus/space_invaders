#ifndef Board_hpp
#define Board_hpp

#include <iostream>
#include <curses.h>
#include <vector>
#include <string.h>
class Drawable;

class Board
{
private:
    int width;
    int height;
    const char *message;
    WINDOW *window;
    std::vector<Drawable *> gameObjects;

public:
    Board();
    ~Board();
    int getHeight();
    int getWidth();
    void update();
    void addObject(Drawable *object);
    int getInput();
    std::vector<Drawable *> getObjects(char representation);
};

#endif
