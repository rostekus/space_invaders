#include <iostream>
#include <curses.h>
#include <iostream>
#include "game.hpp"
int main()
{
    Game *game = new Game();
    game->addPlayerToBoard();
    game->populateBoardwithEnemy();
    game->runGame();
}
