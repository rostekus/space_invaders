#include "game.hpp"
#include "enemy.hpp"
#include "config.hpp"

Game::Game()
{
    board = new Board();
    player = new Player(floor(board->getWidth() / 2), board->getHeight() - 1);
    round = 0;
    midSpace = floor(board->getWidth() / 2);
    numRows = 2;
    numCols = 4;
}

void Game::addPlayerToBoard()
{
    this->board->addObject(this->player);
}
void Game::populateBoardwithEnemy()
{
    for (int i = 0; i < this->numRows; i++)
    {
        for (int j = 0; j < this->numCols; j++)
        {
            Alien *alien = new Alien(this->midSpace - (this->numCols / 2) + j, i + 1);
            this->board->addObject(new Alien(this->midSpace - (this->numCols / 2) + j, i + 1));
        }
    }
}

void Game::runGame()
{
    while (true)
    {
        // Check if game is over
        if (this->player->getLives() <= 0)
        {
            this->board->writeMessage("Game Over.");
            break;
        }
        // Next round
        if (this->board->getObjects(ENEMY_REP).size() == 0)
        {
            this->round++;
            for (int i = 0; i < numRows; i++)
            {
                for (int j = 0; j < numCols; j++)
                {
                    Alien *alien = new Alien(this->midSpace - (this->numCols / 2) + j, i + 1, this->round);
                    board->addObject(new Alien(this->midSpace - (this->numCols / 2) + j, i + 1, this->round));
                }
            }
        }
        // Player loses life when aliens hit bottom
        auto aliens = this->board->getObjects(ENEMY_REP);
        for (auto &alien : aliens)
        {
            if (alien->getPosY() > this->player->getPosY())
            {
                this->player->loseLife();
            }
        }

        this->board->update();
        this->movePlayer();
    }
}

void Game::movePlayer()
{
    int c = this->board->getInput();
    switch (c)
    {
    case RIGHT_KEY:
        if (this->player->getPosX() < this->board->getWidth() - 1)
        {
            this->player->moveRight();
        }
        break;
    case LEFT_KEY:
        if (this->player->getPosX() > 1)
        {
            this->player->moveLeft();
        }
        break;
    case UP_KEY:
        Missile *p = new Missile(true, this->player->getPosX(), this->player->getPosY() - 1);
        this->board->addObject(new Missile(true, this->player->getPosX(), this->player->getPosY() - 1));
        break;
    }
}
