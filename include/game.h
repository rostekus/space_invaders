#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
class Missile;

class Game
{
private:
    int lives;
    int wave;
    int invadersDiv;
    int width;
    int height;
    std::vector<Missile *> playerShots;
    std::vector<Missile *> invadersShots;

public:
    bool isGameOver;
    int score;
    //Player player;
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
