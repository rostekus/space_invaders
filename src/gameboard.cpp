#include <unistd.h>
#include <math.h>
#include <string>
#include "drawable.hpp"
#include "config.hpp"
#include "gameboard.hpp"

Board::Board() : width(DEFAULT_BOARD_WIDTH), height(DEFAULT_BOARD_HEIGHT), message("")
{
    initscr();
    start_color();
    init_color(COLOR_BLACK, 0, 0, 0);
    init_color(COLOR_RED, 1000, 0, 0);
    init_color(COLOR_GREEN, 0, 1000, 0);
    init_color(COLOR_MAGENTA, 1000, 500, 0);
    init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
    init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);
    window = newwin(height, width, 1, 1);
}

Board::~Board()
{
    for (auto &Drawable : gameObjects)
    {
        delete Drawable;
    }
    gameObjects.clear();
    endwin();
    delete window;
    system("clear");
}

int Board::getHeight()
{
    return height - 1;
}

int Board::getWidth()
{
    return width - 1;
}

// MARK: - Board methods
void Board::update()
{
    // Clear the window and then re-draw
    wclear(window);
    box(window, WALL, FLOOR);

    // Draw all game objects in Drawable vector
    for (int i = 0; i < gameObjects.size(); i++)
    {
        Drawable *obj = gameObjects.at(i);
        // Check for any collisions
        for (int j = i + 1; j < gameObjects.size(); j++)
        {
            Drawable *obj2 = gameObjects.at(j);
            if (obj->getPosX() == obj2->getPosX() && obj->getPosY() == obj2->getPosY())
            {
                obj->detectCollision(*obj2);
            }
        }

        if (obj->isDestroyed() || obj->getPosX() > width || obj->getPosY() > height || obj->getPosY() < 0 || obj->getPosX() < 0)
        {
            gameObjects.erase(gameObjects.begin() + i);
            delete obj;
            break;
        }

        // Print game object with color
        wattron(window, COLOR_PAIR(obj->getColor()));
        mvwaddch(window, obj->getPosY(), obj->getPosX(), obj->getRepresentation());
        wattroff(window, COLOR_PAIR(1));
        // Call game objects update function
        obj->update();

        if (strlen(message) > 0)
        {
            int offset = floor(strlen(message) / 2);
            mvwprintw(window, floor(height / 2), floor(width / 2) - offset, message);
        }
    }
    wrefresh(window);
}

std::vector<Drawable *> Board::getObjects(char representation)
{
    std::vector<Drawable *> filtered = std::vector<Drawable *>();
    for (int i = 0; i < gameObjects.size(); i++)
    {
        if (gameObjects.at(i)->getRepresentation() == representation)
            filtered.push_back(gameObjects.at(i));
    }
    return filtered;
}

int Board::getInput()
{
    wtimeout(window, TIMEOUT);
    return wgetch(window);
}

void Board::addObject(Drawable *object)
{
    gameObjects.push_back(object);
}
