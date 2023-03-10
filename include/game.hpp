#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include "gameboard.hpp"
#include "player.hpp"
#include <math.h>

class Missile;

class Game
{
private:
    Board *board;
    Player *player;
    int round;
    int midSpace;
    int numRows;
    int numCols;

public:
    bool isGameOver;
    int score;
    Game();
    ~Game();
    void addPlayerToBoard();
    void populateBoardwithEnemy();
    void runGame();
    void movePlayer();
    void nextRound();
    void checkAlienHitPlayer();
    bool checkGameOver();
    Board *getBoard();
    Player *getPlayer();
};

#endif // GAME_H
