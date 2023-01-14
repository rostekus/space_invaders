#ifndef GAME_H
#define GAME_H
#include "game.h"
#include "player.h"
#include "enemy.h"
#include <iostream>
#include <vector>
using namespace std;

class Game
{
private:
    int lives;
    int wave;
    int invadersDiv;
    Enemy invaders;
    int width;
    int height;
    vector<Missile *> playerShots; //?
    vector<Missile *> invadersShots; //?

public:
    bool isGameOver;
    int score;
    Player player;
    Game();
    ~Game();
    void game();
    void run();
    void draw();
    void movePlayer(int x, int y);
    void firePlayerShot();
    void moveInvaders(int x, int y);
    void fireInvadersShot();
    void moveShots();
};

#endif //GAME_H
